#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

class MyComplex {
   private:
    double real, img;  // �Ǽ���, �����

   public:
    MyComplex(double real, double img) : real(real), img(img) {}
    MyComplex(const MyComplex& c) {  // copy constructor
        real = c.real;
        img = c.img;
    }

    MyComplex operator+(const MyComplex& c) const;
    MyComplex operator-(const MyComplex& c) const;
    MyComplex operator*(const MyComplex& c) const;
    MyComplex operator/(const MyComplex& c) const;

    void println();
};

#endif