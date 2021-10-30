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
    mutable int mut;  // mutable Ű���带 ����ϸ�, const �Լ������� �ش� �� ���� ����

   public:
    explicit MyString(int);  // �Ͻ��� ����ȯ�� �����ϱ� ����(ȿ���� ������� ����)
    // explicit�� ���� �ش� �����ڰ� ���� �������� ���·� ȣ��Ǵ� �� ���� ������
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