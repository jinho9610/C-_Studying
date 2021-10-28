#include "Date.hpp"

int main()
{
    Date day;
    day.SetDate(2021, 3, 1);
    day.ShowDate();

    day.AddDay(33);
    day.ShowDate();

    return 0;
}