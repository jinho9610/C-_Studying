#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

bool readyFlag;
queue<int> q;
condition_variable cv;
mutex mtx2;


void thread1(int* cnt, mutex* mtx)
{
	cout << "thread1" << endl;

	while (true)
	{
		{
			unique_lock<mutex> ul(*mtx);
			//cout << "inserted 100 into Q" << endl;
			q.push(100);
			cv.notify_one();
		}
	}

	//cv.notify_one();
}

void thread2(int* cnt, mutex* mtx)
{
	while (true)
	{
		{
			cout << "eeeeeeeeeeeee" << q.size() << endl;
			unique_lock<mutex> ul(*mtx);
			if (q.empty())
				cv.wait(ul, [&]()->bool {return !q.empty(); });
		}
		mtx2.lock();
		while (!q.empty())
		{
			//cout << q.size() << endl;
			//cout << q.front() << endl;
			q.pop();
		}
		mtx2.unlock();
	}
}

int main()
{
	for (int i = 0; i < 100000; i++)
		q.push(i);

	int cnt = 0;
	mutex mtx;

	thread _t1(thread1, &cnt, &mtx);
	//thread _t2(thread2, &cnt, &mtx);

	int ccnt = 0;
	while (true)
	{
		{
			cout << "Q - EMPTY" << q.size() << endl;
			unique_lock<mutex> ul(mtx);
			if (q.empty())
				cv.wait(ul, [&]()->bool {return !q.empty(); });
		}
		while (!q.empty())
		{
			//cout << q.size() << endl;
			//cout << q.front() << endl;
			ccnt++;
			//cout << ccnt << endl;
			q.pop();
		}
	}

	_t1.join();
	//_t2.join();

	return 0;
}
