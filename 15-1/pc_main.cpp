#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void producer(queue<string>* download_pages, mutex* m, int index, condition_variable* cv) {
    for (int i = 0; i < 5; i++) {
        // 웹페이지를 다운로드하는 시간을 가정하고 sleep
        this_thread::sleep_for(chrono::milliseconds(100 * index));
        string content = "웹사이트 : " + to_string(i) +
                         " from thread(" + to_string(index) + ")\n";

        // q는 전역적으로 공유되고 있으므로 race condition이 발생 가능한 공유자원임
        // 따라서 하기 코드는 임계 영역이므로 mutex로 감싸서 보호
        m->lock();
        download_pages->push(content);
        m->unlock();

        // 처리할 contents를 막 q에 push했으니, consumer에게 할 일이 있음을 알려줌
        cv->notify_one();
    }
}

void consumer(queue<string>* download_pages, mutex* m, int* num_processed, condition_variable* cv) {
    while (*num_processed < 25) {   // q에서 pop하고 출력한 page가 25개가 될 때 까지
        unique_lock<mutex> lk(*m);  // mutex를 감싼 unique lock 생성
        // q에 다운로드된 콘텐츠가 없다면 lock을 해제함
        // 그래야 provider에서 q에 콘텐츠 push 가능

        cv->wait(
            lk, [&] {
                // q가 비어있지 않거나, 처리한 contents 개수가 25개가 되면
                // wake up!
                return !download_pages->empty() || *num_processed == 25;
            });

        // *num_processed == 25 조건에 의해서 wake up된 경우
        if (*num_processed == 25) {
            lk.unlock();
            return;
        }

        string content = download_pages->front();
        download_pages->pop();

        ++(*num_processed);
        lk.unlock();

        cout << content;
        this_thread::sleep_for(chrono::milliseconds(80));
    }
}

int main() {
    queue<string> download_pages;
    mutex m;
    condition_variable cv;

    vector<thread> producers, consumers;

    for (int i = 0; i < 5; i++) {
        producers.push_back(
            thread(producer, &download_pages, &m, i + 1, &cv));
    }

    int num_processed = 0;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(
            thread(consumer, &download_pages, &m, &num_processed, &cv));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }

    cv.notify_all();

    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }

    return 0;
}