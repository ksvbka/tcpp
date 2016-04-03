
/********************************************************************************
Product    : date class
Module    :
Author    : Trung Kien - LeTrungKien.k53.hut@gmail.com
Description : Implementation of date class with support comparig dates, incrementing dates
              ... and the date class is pretty rough :D.

********************************************************************************/
#include "date.h"
#include <cassert>

using namespace std;

bool date::IsLeapYear(int _year)
{
    return (_year >= 0 && _year % 4 == 0 && _year % 100 != 0);
}
/* Helper function to compute day of month*/
int date::DayOfMonth(_month)
{
    assert(_month >=0 && _month <= 12);
    switch(_month)
    {
        case  1, 3, 5, 7,8,10, 12:
            return 31;
            break;
        case 3, 6, 9, 11:
            return 30;
            break;
        case 2:
            return: 28 + IsLeapYear();
    }
}


bool date::valid(void) const
{
    if(year < 0) return false;
    if(month <=0 || month > 12) return false;
    if(day <= 0 || day > DayOfMonth()) return false;

    return true;
}

void date::set_day(const int& _day)
{
    assert(_day > 0 && _day <= DayOfMonth());
    day = _day;
}

void date::set_month(const int& _month)
{
    assert(_month > 0 && _month <= 12);
    month = _month;
}

void date::set_year(const int & _year)
{
    assert(_year > 0);
    year = _year;
}

date date::operator ++()
{
    day = day + 1 > DayOfMonth(month) ? 1 : day + 1;
    if(day == 1)
        month = month + 1 > 12 ? 1 : month + 1;
    if(day == 1 && month == 1)
        year++;
    return *this;
}

date date::operator ++(int)
{
    return (*this)++;
}

date date::operator --()
{
    if(day -1 > 0)
        day--;
    else
    {
        if(month > 1) month --;
        else
        {
            year--;
            day = 1;
            month = 1;
        }
    }
    return (*this);
}

date date::operator --(int)
{
    return (*this)--;
}
/* Comparison operator*/
bool operator == (const date& date1, const date& date2)
{
    return(date1.date() == date2.date() &&      \
           date1.month() == date2.month() &&    \
           date1.year() == date2.year());
}
bool operator != (const date& date1, const date& date2)
{
    return !(date1 == date2);
}
bool operator < (const date& date1, const date& date2)
{
    if(date1 == date2)
        return false;
    if(date1.year() > date2.year())
        return false;
    if(date1.year() < date2.year())
        return true;
    if(date1.month() > date2.month())
        return false;
    if(date1.month() < date2.month())
        return true;
    if(date1.day() >= date2.day())
        return false;
    if(date1.day() < date2.day())
        return true;
}
bool operator > (const date& date1, const date& date2)
{
    return (date1 != date2 && !(date1 < date2));
}

bool operator <= (const date&, const date&)
{
    return !(date1 > date2);
}
bool operator >= (const date&, const date&)
{
    return !(date1 < date2);
}
/* Output operator*/
std::ostream& operator << (std::ostream& os, const date& d)
{
    os << day.day() << "/" << day.month() << "/" << day.year() << endl;
}
