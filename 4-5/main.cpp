#include "MyString.hpp"

void do_something(const MyString& str) {
    cout << str.length() << endl;
    cout << "�Ͻ��� ����ȯ �ľ��� ���� dummy method ȣ��\n"
         << endl;
}

int main() {
    do_something(MyString("jinho"));
    do_something("jinho");  // �� ��� "jinho" -> MyString("jinho") �Ͻ��� ����ȯ �߻�
    do_something(3);
    MyString("mutable").change();  // mutable Ű���� �׽�Ʈ

    return 0;
}