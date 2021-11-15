#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void producer(queue<string>* download_pages, mutex* m, int index) {
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
    }
}

void consumer(queue<string>* download_pages, mutex* m, int* num_processed) {
    while (*num_processed < 25) {  // q에서 pop하고 출력한 page가 25개가 될 때 까지
        m->lock();
        // q에 다운로드된 콘텐츠가 없다면 lock을 해제함
        // 그래야 provider에서 q에 콘텐츠 push 가능
        if (download_pages->empty()) {
            m->unlock();
            // 아무런 contents 없다면 10ms 대기하며 provider가 q에
            // 콘텐츠 push 하기를 대기
            this_thread::sleep_for(chrono::milliseconds(10));
            // 무의미한 empty() 함수 호출 및 확인 과정을 "그나마" 방지하기 위해 10ms 대기함
            // condition value를 활용하면, 처리할 콘테츠가 있을 때만 스레드가 깨어나게 할 수 있음
            continue;
        }

        string content = download_pages->front();
        download_pages->pop();

        ++(*num_processed);
        m->unlock();

        cout << content;
        this_thread::sleep_for(chrono::milliseconds(80));
    }
}

int main() {
    queue<string> download_pages;
    mutex m;

    vector<thread> producers, consumers;

    for (int i = 0; i < 5; i++) {
        producers.push_back(
            thread(producer, &download_pages, &m, i + 1));
    }

    int num_processed = 0;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(
            thread(consumer, &download_pages, &m, &num_processed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }

    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }

    return 0;
}