#include <iostream>

#include "MyComplex.hpp"

using namespace std;

int main() {
    MyComplex a(1.0, 2.0);
    MyComplex b(3.0, -5.0);

    MyComplex c = a + b;

    c.println();

    return 0;
}