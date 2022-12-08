#include "ThreadPool.h"
ThreadPool* ThreadPool::instance = nullptr;
ThreadPool::ThreadPool(size_t _num_threads)
	:num_threads_(_num_threads), stop_all(false)
{
	worker_threads_.reserve(num_threads_);
	for (int i = 0; i < num_threads_; ++i)
	{
		worker_threads_.push_back(new std::thread([this]()->void{this->WorkerThread();}));
	}
}
ThreadPool::~ThreadPool()
{
	stop_all = true;
	cv_job_q_.notify_all();
	for (std::thread* th : worker_threads_)
	{
		th->join();
		
	}
	for (std::thread* th : worker_threads_)
	{
		delete th;
		th = nullptr;
	}
}

void ThreadPool::WorkerThread()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(m_job_q_);
		cv_job_q_.wait(lock, [this]() {return !this->jobs_.empty() || stop_all; });
		if (stop_all && this->jobs_.empty())
			return;

		std::function<void()> job = std::move(jobs_.front());
		jobs_.pop();
		lock.unlock();

		job();
	}
}

//void ThreadPool::EnqueueJob(std::function<void()> job)
//{
//	if (stop_all)
//		throw std::runtime_error("ThreadPool 사용이 종료됨.");
//
//	{
//		std::lock_guard<std::mutex> lock(m_job_q_);
//		jobs_.push(std::move(job));
//	}
//	cv_job_q_.notify_one();
//}

void ThreadPool::CreateInstance(size_t _num_threads)
{
	if (instance == nullptr)
		instance = new ThreadPool(_num_threads);
}

void ThreadPool::DestroyInstance()
{
	instance->~ThreadPool();
	delete instance;
	instance = nullptr;
}

ThreadPool* ThreadPool::GetInstance()
{
	if (instance == nullptr)
		return nullptr;

	return instance;
}
