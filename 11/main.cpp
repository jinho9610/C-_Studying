#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
   private:
    T* data_;
    size_t size_;

   public:
    Vector(size_t size) : size_(size) {
        data_ = new T[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = 3;
        }
    }

    ~Vector() {
        delete[] data_;
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw out_of_range("vector의 index가 범위를 초과했습니다.");
        }
        return data_[index];
    }
};

int main() {
    Vector<int> v(3);  // size가 3이고 모든 원소가 3인 벡터 생성
    int idx, data;

    cout << "[idx : 1 일 때 예외발생 테스트]\n";
    idx = 1;
    try {
        data = v.at(idx);
    } catch (out_of_range& e) {
        cout << "<<<out-of-range 예외 발생!>>>\n"
             << e.what() << endl;
    }

    cout << "[idx : 3 일 때 예외발생 테스트]\n";
    idx = 3;
    try {
        data = v.at(idx);
    } catch (out_of_range& e) {
        cout << "<<<out-of-range 예외 발생!>>>\n"
             << e.what() << endl;
    }
}