#include "MyString.hpp"

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i < string_length; ++i)
        string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
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

void MyString::print() {
    cout << string_content;
}

void MyString::println() {
    cout << string_content << endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > this->string_length) {
        delete[] this->string_content;
        this->string_content = new char[str.string_length];
    }

    for (int i = 0; i < str.string_length; ++i)
        this->string_content[i] = str.string_content[i];

    this->string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    if (strlen(str) > this->string_length) {
        delete[] this->string_content;
        this->string_content = new char[strlen(str)];
    }

    for (int i = 0; i < strlen(str); ++i)
        this->string_content[i] = str[i];

    this->string_length = strlen(str);

    return *this;
}