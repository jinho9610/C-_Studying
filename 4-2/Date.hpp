#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using namespace std;

class Date
{
private:
    int year_;
    int month_;
    int day_;

public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    // 해당 월의 총 일 수를 계산 및 반환
    int GetCurrentMonthTotalDays(int year, int month);
    void ShowDate();
};

#endif