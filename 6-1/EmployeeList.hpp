#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.hpp"
#include "Manager.hpp"

class EmployeeList {
   private:
    int alloc_employee;        // 할당 가능한 최대 직원 수
    int current_employee;      // 현재 직원(사원 + 매니저) 수
    Employee** employee_list;  // Employee 또는 Manager 객체 저장

   public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee*[alloc_employee];
        current_employee = 0;  // 최초 사원 수 0명
    }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; ++i) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }

    void add_employee(Employee* employee) {  // 사원 또는 매니저 추가
        // 최대 할당 가능 직원수보다 현재 직원수가 늘 작다고 가정
        employee_list[current_employee++] = employee;
    }

    int current_employee_num() const {
        return current_employee;
    }

    void print_employee_info() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; ++i) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        cout << "총 인건비 : " << total_pay << "$" << endl;
    }
};

#endif