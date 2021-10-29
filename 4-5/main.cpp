#include "MyString.hpp"

int main() {
    MyString str("jinho");
    MyString str2(str);

    str.println();
    str.assign("jacob");
    str.println();
    str2.println();

    return 0;
}