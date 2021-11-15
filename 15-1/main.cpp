#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
    int sum = 0;
    for (auto it = start; it < end; ++it) {
        sum += *it;
    }
    *result = sum;

    cout << "쓰레드 ID: " << this_thread::get_id() << " --> "
         << *start << " ~ " << *end << "까지 합 계산: "
         << *result << endl;
}

int main() {
    vector<int> data(10000);
    for (int i = 0; i < 10000; i++) {
        data[i] = i;
    }

    vector<int> partial_sums(4);  // 2500개 씩 부분 합을 구하여 저장함

    vector<thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(
            thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500,
                   &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    return 0;
}