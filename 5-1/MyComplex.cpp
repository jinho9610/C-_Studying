#include "MyComplex.hpp"

#include <iostream>

using namespace std;

//Complex::

MyComplex MyComplex::operator+(const MyComplex& c) const {
    return MyComplex(real + c.real, img + c.img);
}

MyComplex MyComplex::operator-(const MyComplex& c) const {
    return MyComplex(real - c.real, img - c.img);
}

MyComplex MyComplex::operator*(const MyComplex& c) const {
    return MyComplex(real * c.real - img * c.img, real * c.img + img * c.real);
}

MyComplex MyComplex::operator/(const MyComplex& c) const {
    if (c.real == 0 && c.img == 0)
        cout << "0 divide error!" << endl;

    return MyComplex(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
}

void MyComplex::println() {
    cout << real;
    if (img < 0) {
        cout << img << "i" << endl;
    } else if (img > 0) {
        cout << "+" << img << "i" << endl;
    } else {
    }
}