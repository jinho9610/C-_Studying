#include "Date.hpp"

void Date::SetDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
    // static 변수이므로 이 함수 외부에서도 살아는 있으나 (왜 사용하지?)
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2)
        return month_day[month - 1];
    else if (year % 4 == 0 && year % 100 != 0) // 윤년 2월
        return 29;
    else // 윤년이 아닌 2월
        return 28;
}

void Date::AddDay(int inc)
{
    while (true)
    {
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        // 다음달로 넘어가는 경우
        if (day_ + inc <= current_month_total_days)
        {
            day_ += inc;
            return;
        }
        else
        {
            inc -= (current_month_total_days - day_ + 1);
            day_ = inc;
            AddMonth(1); // 1개월 증가
        }
    }
}

void Date::AddMonth(int inc)
{
    AddYear((inc + month_ - 1) / 12);
    month_ += inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate()
{
    cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다." << endl;
}