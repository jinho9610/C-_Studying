#include "header1.h"
#include "header2.h"
#include <iostream>

using namespace std;
using namespace header2;

int main()
{
    header1::h1_print(); // using namespace header1이 없으므로 header1:: 없이는 불가
    h2_print();

    return 0;
}