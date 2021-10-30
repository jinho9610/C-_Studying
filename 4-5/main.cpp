#include "MyString.hpp"

void do_something(const MyString& str) {
    cout << str.length() << endl;
    cout << "암시적 형변환 파악을 위한 dummy method 호출\n"
         << endl;
}

int main() {
    do_something(MyString("jinho"));
    do_something("jinho");  // 이 경우 "jinho" -> MyString("jinho") 암시적 형변환 발생
    do_something(3);
    MyString("mutable").change();  // mutable 키워드 테스트

    return 0;
}