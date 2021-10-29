#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>

#include <iostream>

using namespace std;

class MyString {
   private:
    char* string_content;  // pointer of string data
    int string_length;

   public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length() const;
    void print();
    void println();

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
};

#endif