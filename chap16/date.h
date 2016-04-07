
/********************************************************************************
Product    : date class
Module    :
Author    : Trung Kien - LeTrungKien.k53.hut@gmail.com
Description : Implementation of date class with support comparig dates,
              incrementing dates... and the date class is pretty rough :D.

********************************************************************************/
#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

namespace kr {

class date {
  public:
    date(): day_(0), month_(0), year_(0) {};

    date(const int& d , const int& m , const int& y);

    date( long long day);

    date(const date& rhs);

    int day() const     { return day_;   };
    int month() const   { return month_; };
    int year() const    { return year_;  };

    void set_day(const int& day_);
    void set_month(const int& month_);
    void set_year(const int& year_);

    date operator ++(); /* Prefix*/
    date operator ++(int); /* Postfix*/
    date operator --(); /* Prefix*/
    date operator --(int); /* Postfix*/
  private:
    int year_;
    int month_;
    int day_;
    bool is_valid();

};

/* Helper function */

int  IsLeapYear(const int& year);
int  DayOfMonth(const int& month, const int& year);
bool IsValidDay(const int& day, const int& month, const int& year);
date defaultDay();

bool operator == (const date& , const date&); /* Comparison operator*/
bool operator != (const date& , const date&);
bool operator <  (const date&, const date&);
bool operator >  (const date&, const date&);

bool operator <= (const date&, const date&);
bool operator >= (const date&, const date&);

std::ostream& operator << (std::ostream& os, const date& d); /* Output operator*/
} // namespace kr

#endif // __DATE_H__

