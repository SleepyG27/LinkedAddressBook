#include "dateType.h"

// Default constructor
dateType::dateType() {
    month = 1;
    day = 1;
    year = 1900;
}

// Constructor with parameters
dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

// Function to set the date
void dateType::setDate(int month, int day, int year) {
    if (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= getDaysInMonth(month, year)) {
        this->month = month;
        this->day = day;
        this->year = year;
    } else {
        cout << "Date invalid, setting to 1/1/1900" << endl;
        this->month = 1;
        this->day = 1;
        this->year = 1900;
    }
}

// Function to print the date 
void dateType::print() const {
    cout << month << "/" << day << "/" << year;
}

// Function to check if a year is a leap year
bool dateType::isLeapYear(int year) const {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return true;
    }
    return false;
}

// Function to get the number of days in a month for a given year
int dateType::getDaysInMonth(int month, int year) const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

// Helper function to validate the date
bool dateType::isValidDate(int month, int day, int year) const {
    return (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= getDaysInMonth(month, year));
}
