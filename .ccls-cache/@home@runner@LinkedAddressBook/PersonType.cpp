#include "extPersonType.h"

// Constructor with parameters
extPersonType::extPersonType(dateType birthDate, addressType address, string phoneNumber, string relationship) {
    this->birthDate = birthDate;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->relationship = relationship;
}

// Function to print the person's information
void extPersonType::printInfo() const {
    cout << "Birth Date: ";
    birthDate.print();
    cout << "Address: ";
    address.print();
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Relationship: " << relationship << endl;
}
