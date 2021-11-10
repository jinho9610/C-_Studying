#include <iostream>
#include <utility>

using namespace std;

class A {
   public:
    A() {
        cout << "일반 생성자 호출!" << endl;
    }
    A(const A& a) {
        cout << "복사 생성자 호출!" << endl;
    }
    A(A&& a) {  // 우측값 레퍼런스
        cout << "이동 생성자 호출!" << endl;
    }
};

int main() {
    A a;  // 일반

    cout << "---------------" << endl;
    A b(a);  // 복사

    cout << "---------------" << endl;
    A c(move(a));  // 우측값 레퍼런스 활용한 이동 생성자
}