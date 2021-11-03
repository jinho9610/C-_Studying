#ifndef MANAGER_H
#define MANAGER_H

#include <string.h>

#include <iostream>

using namespace std;

class Manager {
   private:
    string name;  // 이름
    int age;      // 나이

    string position;      // 직책
    int rank;             // 직급
    int year_of_service;  // 근속 연수

   public:
    Manager(string name, int age, string position, int rank, int year_of_service)
        : name(name), age(age), position(position), rank(rank), year_of_service(year_of_service) {}  // 초기화 리스트 사용한느 생성자

    Manager(const Manager& manager) {
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }

    void print_info() {
        cout << name << " (" << position << ", " << age << ", " << year_of_service
             << "년차) -->" << calculate_pay() << "$" << endl;
    }

    int calculate_pay() const {
        return 200 + rank * 50 + 5 * year_of_service;
    }
};

#endif