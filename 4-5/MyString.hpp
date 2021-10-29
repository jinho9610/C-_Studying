#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>

#include <iostream>

using namespace std;

class MyString {
   private:
    char* string_content;  // pointer of string data
    int string_length;
    int memory_capacity;

   public:
    MyString(char);
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();

    int length() const;
    int capacity() const;
    void print();
    void println();

    MyString& assign(const MyString&);
    MyString& assign(const char*);

    void reserve(int);
};

#endif