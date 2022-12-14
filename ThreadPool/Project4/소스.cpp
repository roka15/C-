#include "ThreadPool.h"

int work(int t, int id)
{
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}
int main()
{
	ThreadPool::CreateInstance(3);
	std::vector<std::future<int>> futures;
	std::packaged_task<int()> task(std::bind(work, 1, 1));
	for (int i = 0; i < 10; i++)
	{
		futures.emplace_back(ThreadPool::GetInstance()->EnqueueJob(work,i%3+1,i));
	}

	for (auto& f : futures)
	{
		printf("result : %d \n", f.get());
	}
	ThreadPool::DestroyInstance();

	
}