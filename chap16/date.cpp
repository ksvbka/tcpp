
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

namespace kr{

    /* Helper function */
    int IsLeapYear(const int& year)
    {
        return (year >= 0 && year % 4 == 0 && year % 100 != 0);
    }

    /* Helper function to compute day of month*/
    int  DayOfMonth(const int& month, const int& year)
    {
        assert(month >=0 && month <= 12);
        switch(month)
        {
            case 1: case 3: case 5 : case 7 :case 8 :case 10 :case 12:
                return 31;
                break;
            case 4: case 6: case 9 :case 11:
                return 30;
                break;
            case 2:
                return 28 + IsLeapYear(year);
        }
    }

    date defaultDay()
    {
        date zeroDay(1,1,0);
        return zeroDay;
    }

    bool IsValidDay(const int& day, const int& month, const int& year)
    {
        if(year < 0)
            return false;
        if(month <=0 || month > 12)
            return false;
        if(day <= 0 || (day > DayOfMonth(month, year)))
            return false;

        return true;
    }

    /* Construction*/
    bool date::is_valid()
    {
        return IsValidDay(day_, month_, year_);
    }

    date::date(const int &day, const int& month, const int& year)
        : day_(day), month_(month), year_(year)
    {
        if(!is_valid())
        {
            day_    = defaultDay().day();
            month_  = defaultDay().month();
            year_   = defaultDay().year();
        }
    }

    date::date( long long longDay)
    {
        assert(longDay >= 0);
        day_ = static_cast<int>(longDay % 100);
        longDay /= 100;
        month_ = static_cast<int>(longDay %100);
        longDay /= 100;
        year_ = static_cast<int>(longDay);

        if(is_valid())
        {
            *this = defaultDay();
        }
    }

    date::date(const date& rhs)
    {
        day_   = rhs.day_;
        month_ = rhs.month_;
        year_  = rhs.year_;
    }

    void date::set_day(const int& day)
    {
        assert(day > 0 && (day <= DayOfMonth(month_, year_)));
        day_ = day;
    }

    void date::set_month(const int& month)
    {
        assert(month > 0 && month <= 12);
        month_ = month;
    }

    void date::set_year(const int & year)
    {
        assert(year > 0);
        year_ = year;
    }

    date date::operator ++()
    {
        day_ = day_ + 1 > DayOfMonth(month_, year_) ? 1 : day_ + 1;
        if(day_ == 1)
            month_ = month_ + 1 > 12 ? 1 : month_ + 1;
        if(day_ == 1 && month_ == 1)
            year_++;
        return (*this);
    }

    date date::operator ++(int)
    {
        return ++(*this);
    }

    date date::operator --()
    {

        if(day_ -1 > 0)
            day_--;
        else
        {
            if(month_ > 1)
            {
                month_--;
                day_ = DayOfMonth(month_, year_);
            }
            else
            {
                year_--;
                month_ = 12;
                day_ = 31;
            }
        }
        return (*this);
    }

    date date::operator --(int)
    {
        return --(*this);
    }
    /* Comparison operator*/
    bool operator == (const date& date1, const date& date2)
    {
        return(date1.day() == date2.day() &&      \
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

    bool operator <= (const date& date1, const date& date2)
    {
        return !(date1 > date2);
    }
    bool operator >= (const date& date1, const date& date2)
    {
        return !(date1 < date2);
    }

    /* Output operator*/
    std::ostream& operator << (std::ostream& os, const date& d)
    {
        os << d.day() << "/" << d.month() << "/" << d.year() << endl;
    }

}
