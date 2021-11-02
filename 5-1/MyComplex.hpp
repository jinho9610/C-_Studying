#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

class MyComplex {
   private:
    double real, img;  // 실수부, 허수부

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