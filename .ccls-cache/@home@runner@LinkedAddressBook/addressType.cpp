#include "addressType.h"

// Default constructor
addressType::addressType() {
    street = "";
    city = "";
    state = "";
    zipCode = 0;
}

// Constructor with parameters
addressType::addressType(string street, string city, string state, int zipCode) {
    setAddress(street, city, state, zipCode);
}

// Function to set the address
void addressType::setAddress(string street, string city, string state, int zipCode) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

// Function to print the address
void addressType::print() const {
    cout << street << ", " << city << ", " << state << " " << zipCode << endl;
}
