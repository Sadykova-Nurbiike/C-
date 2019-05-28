#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ostream>

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day);

    Date(const Date& other) {
        this->year = other.year;
        this->month = other.month;
        this->day = other.day;
    }


    // The reason why the following methods are declared as 'const', these methods will be called on const parameter objects in operator== method.
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }


    bool operator==(const Date &other) {
    return (this->year == other.getYear() && this->month == other.getMonth() && this->day == other.getDay());
    }

    int operator<(const Date &other) {
        if(this->year == other.getYear()) {
            if(this->month == other.getMonth()) {
                return(this->day < other.getDay());
            }
            return(this->month < other.getMonth());
        }

        return this->year < other.getYear();
    }

    Date nextDay() {
        Date tmp = *this;
    }

};

#endif // DATE_H
