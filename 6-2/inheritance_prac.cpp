#include <iostream>
#include <string>

using namespace std;

class Base {
    string s;

   public:
    Base() : s("부모") {
        cout << "부모 클래스 호출" << endl;
    }

    virtual void what() {
        cout << "부모 클래스 WHAT 함수 호출..." << endl;
    }
};

class Derived : public Base {
    string s;

   public:
    Derived() : s("자식"), Base() {
        cout << "자식 클래스 호출" << endl;
    }

    void what() {
        cout << "자식 클래스 WHAT 함수 호출..." << endl;
    }
};

int main() {
    Base p;
    Derived c;

    cout << "<<상속 관계에서의 포인터 공부>>" << endl;

    cout << "[업 캐스팅]" << endl;
    Base* p_c = &c;  // 자식 클래스 객체를 부모 클래스 포인터로 가리킴
    p_c->what();     // 부모 클래스의 what과 자식 클래스 what 중 무엇이 호출될까?
    // 부모 클래스의 what이 호출됨

    cout << "[다운 캐스팅]" << endl;
    //Derived* p_p = p_c; // 컴파일 에러
    Derived* p_p = static_cast<Derived*>(p_c);
    // virtual로 인한 동적 바인딩(객체를 가리키는 포인터가,
    // 부모 클래스 포인터여도
    // 객체가 자식 클래스 객체이므로 자식 클래스의 WHAT 함수 호출)
    p_p->what();

    return 0;
}