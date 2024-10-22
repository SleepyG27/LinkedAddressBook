#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>
using namespace std;

class addressType {
private:
    string street;
    string city;
    string state;
    int zipCode;

public:
    // Default constructor
    addressType();

    // Constructor with parameters
    addressType(string street, string city, string state, int zipCode);

    // Function to set the address
    void setAddress(string street, string city, string state, int zipCode);

    // Function to print the address
    void print() const;
};

#endif
