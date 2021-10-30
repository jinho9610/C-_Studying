#include "MyString.hpp"

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1, memory_capacity = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];
    memory_capacity = strlen(str);

    for (int i = 0; i < string_length; ++i)
        string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i < string_length; ++i)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() {
    delete[] string_content;
}

int MyString::length() const {
    return string_length;
}

int MyString::capacity() const {
    return memory_capacity;
}

void MyString::print() {
    cout << string_content;
}

void MyString::println() {
    cout << string_content << endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > this->memory_capacity) {
        delete[] this->string_content;
        this->string_content = new char[str.string_length];

        this->memory_capacity = str.string_length;
    }

    for (int i = 0; i < str.string_length; ++i)
        this->string_content[i] = str.string_content[i];

    this->string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    if (strlen(str) > this->memory_capacity) {
        delete[] this->string_content;
        this->string_content = new char[strlen(str)];

        this->memory_capacity = strlen(str);
    }

    for (int i = 0; i < strlen(str); ++i)
        this->string_content[i] = str[i];

    this->string_length = strlen(str);

    return *this;
}

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;  // 이전 문자열 포인터
        string_content = new char[size];             // size 만큼 새로 할당 받음
        this->memory_capacity = size;

        // 이전 문자열을 새롭게 할당 받은 공간으로 옮기기
        for (int i = 0; i < string_length; ++i)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char MyString::at(int idx) const {
    if (idx < 0 || idx >= string_length)
        return NULL;

    else
        return string_content[idx];
}