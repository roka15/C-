#pragma once
#include "global.h"

class ThreadPool
{
private:
	size_t num_threads_;
	std::vector<std::thread*> worker_threads_;
	std::queue<std::function<void()>> jobs_;
	std::condition_variable cv_job_q_;
	std::mutex m_job_q_;
	bool stop_all;
	static ThreadPool* instance;
private:
	ThreadPool(size_t _num_threads);
	~ThreadPool();
	void WorkerThread();

public:
	static void CreateInstance(size_t _num_threads);
	static void DestroyInstance();
	static ThreadPool* GetInstance();
public:

	//void EnqueueJob(std::function<void()>job);
	template<class F, class...Args>
	std::future<typename std::invoke_result<F, Args...>::type> EnqueueJob(F f, Args... args);

	//c++14
	/*template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
		F f, Args... args);*/
};
#pragma region c++17

template<class F, class ...Args>
inline std::future<typename std::invoke_result<F, Args...>::type> ThreadPool::EnqueueJob(F f, Args ...args)
{
	if (stop_all)
	{
		throw std::runtime_error("ThreadPool Stop");
	}

	using return_type = typename std::invoke_result<F, Args...>::type;
	auto job = std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));
	std::future<return_type> job_result_future = job->get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		jobs_.push([job]() {(*job)(); });
	}
	cv_job_q_.notify_one();

	return job_result_future;
}
#pragma endregion
#pragma region c++14
/*
template<class F, class ...Args>
inline std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F f, Args ...args)
{
	if (stop_all) {
		throw std::runtime_error("ThreadPool »ç¿ë ÁßÁöµÊ");
	}

	using return_type = typename std::result_of<F(Args...)>::type;
	auto job =
		std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));
	std::future<return_type> job_result_future = job->get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		jobs_.push([job]() { (*job)(); });
	}
	cv_job_q_.notify_one();

	return job_result_future;
}
*/
#pragma endregion