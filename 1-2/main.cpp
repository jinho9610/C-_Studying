#include "header1.h"
#include "header2.h"
#include <iostream>

using namespace std;
using namespace header2;

int main()
{
    header1::h1_print(); // using namespace header1�� �����Ƿ� header1:: ���̴� �Ұ�
    h2_print();

    return 0;
}