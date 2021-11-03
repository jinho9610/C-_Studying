#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string.h>

#include <iostream>

using namespace std;

class Employee {
   protected:
    string name;  // 이름
    int age;      // 나이

    string position;  // 직책
    int rank;         // 직급

   public:
    Employee(string name, int age, string position, int rank) : name(name), age(age), position(position), rank(rank) {}  // 초기화 리스트 사용한느 생성자

    Employee(const Employee& employee) {
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

    Employee() {}  // default

    void print_info() {
        cout << name << " (" << position << ", " << age << ") --> " << calculate_pay() << "$" << endl;
    }

    int calculate_pay() const {
        return 200 + rank * 50;
    }
};

#endif