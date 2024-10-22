#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>
using namespace std;

class dateType {
private:
    int month;
    int day;
    int year;

public:
    // Default constructor
    dateType();

    // Constructor with parameters
    dateType(int month, int day, int year);

    // Function to set the date
    void setDate(int month, int day, int year);

    // Function to print the date in MM/DD/YYYY
    void print() const;

    // Function to check if a year is a leap year
    bool isLeapYear(int year) const;

    // Function to get the number of days in a month for a given year
    int getDaysInMonth(int month, int year) const;

    // Helper function to validate the date
    bool isValidDate(int month, int day, int year) const;
};

#endif
