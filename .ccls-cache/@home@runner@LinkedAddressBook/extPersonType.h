#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include <iostream>
#include "dateType.h"
#include "addressType.h"

class extPersonType {
private:
    dateType birthDate;
    addressType address;
    std::string phoneNumber;
    std::string relationship;
    std::string firstName; // Add firstName
    std::string lastName;  // Add lastName

public:
    // Constructor
    extPersonType(const std::string& firstName, const std::string& lastName,
                  const dateType& birthDate, const addressType& address,
                  const std::string& phoneNumber, const std::string& relationship);

    // Function to print the person's information
    void printInfo() const;
};

#endif
