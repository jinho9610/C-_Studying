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
    mutable int mut;  // mutable 키워드를 사용하면, const 함수에서도 해당 값 변경 가능

   public:
    explicit MyString(int);  // 암시적 형변환을 방지하기 위함(효율적 디버깅을 위해)
    // explicit은 또한 해당 생성자가 복사 생성자의 형태로 호출되는 것 또한 방지함
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
    char at(int) const;

    void change() const;
};

#endif