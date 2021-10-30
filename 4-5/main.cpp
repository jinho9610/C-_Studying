#include "MyString.hpp"

int main() {
    MyString str1("very very very long string");
    cout << "Cpacity : " << str1.capacity() << endl;
    str1.reserve(40);

    cout << "Cpacity : " << str1.capacity() << endl;
    cout << "String length : " << str1.length() << endl;

    if (str1.at(-1) != NULL)
        cout << str1.at(-1) << endl;

    return 0;
}