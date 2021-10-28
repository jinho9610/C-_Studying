#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using namespace std;

class Date {
   private:
    int year_;
    int month_;
    int day_;

   public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetCurrentMonthTotalDays(int year, int month);
    void ShowDate();
};

#endif