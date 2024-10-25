#pragma once

#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>
#include <stdexcept>

using namespace std; // Added this line to use std namespace

class dateType {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    dateType() : day(1), month(1), year(1900) {}

    // Parameterized constructor with basic validation
    dateType(int m, int d, int y) {
        if (m < 1 || m > 12 || d < 1 || d > 31 || y < 1900) {
            throw invalid_argument("Invalid date");
        }
        month = m;
        day = d;
        year = y;
    }

    // Accessor functions
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

#endif // DATETYPE_H
