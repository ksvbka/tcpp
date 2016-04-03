
/********************************************************************************
Product    : date class
Module    :
Author    : Trung Kien - LeTrungKien.k53.hut@gmail.com
Description : Implementation of date class with support comparig dates, incrementing dates
              ... and the date class is pretty rough :D.

********************************************************************************/
#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class date
{
protected:
    int year;
    int month;
    int day;
    // enum Month {Jan =1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec  };
public:
    date(const int& d = 1, const int& m = 1, const int& y = 0) :
        day(d), month(m), year(y) {};

    int day() const     { return day;   };
    int month() const   { return month; };
    int year() const    { return year;  };

    bool valid(void) const;

    void set_day(const int& day);
    void set_month(const int& month);
    void set_year(const int& year);

    date operator ++(); /* Prefix*/
    date operator ++(int); /* Postfix*/
    date operator --(); /* Prefix*/
    date operator --(int); /* Postfix*/

};

/* Helper function*/

bool operator == (const date& , const date&); /* Comparison operator*/
bool operator != (const date& , const date&);
bool operator < (const date&, const date&);
bool operator > (const date&, const date&);

bool operator <= (const date&, const date&);
bool operator >= (const date&, const date&);

std::ostream& operator << (std::ostream& os, const date& d); /* Output operator*/

#endif // __DATE_H__
