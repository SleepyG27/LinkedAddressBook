#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include "dateType.h"
#include "addressType.h"
#include <string>
using namespace std;

class extPersonType {
private:
    dateType birthDate;
    addressType address;
    string phoneNumber;
    string relationship;

public:
    // Constructor with parameters
    extPersonType(dateType birthDate, addressType address, string phoneNumber, string relationship);

    // Function to print the person's information
    void printInfo() const;
};

#endif
