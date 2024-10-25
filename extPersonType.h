#pragma once
#include <iostream>
#include <string>
#include "dateType.h"

using namespace std; 

class extPersonType {
private:
    string firstName;
    string lastName;
    string relationship;
    dateType birthDate;
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string phoneNumber;

public:
    // Constructor
    extPersonType(const string& fName = "", const string& lName = "", 
                  const string& rel = "", const dateType& bDate = dateType(), 
                  const string& street = "", const string& city = "", 
                  const string& state = "", const string& zip = "", 
                  const string& phone = "")
        : firstName(fName), lastName(lName), relationship(rel), birthDate(bDate),
          streetAddress(street), city(city), state(state), zipCode(zip), phoneNumber(phone) {}

    // Accessor methods
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getRelationship() const { return relationship; }
    dateType getBirthDate() const { return birthDate; }
    string getStreetAddress() const { return streetAddress; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZipCode() const { return zipCode; }
    string getPhoneNumber() const { return phoneNumber; }

    // Overloaded comparison operators
    bool operator<(const extPersonType& other) const {
        if (lastName < other.lastName) {
            return true;
        }
        else if (lastName == other.lastName) {
            return firstName < other.firstName;
        }
        return false;
    }

    bool operator>=(const extPersonType& other) const {
        return !(*this < other); // Greater than or equal to
    }

    // Overloaded equality operator
    bool operator==(const extPersonType& other) const {
        return (firstName == other.firstName && lastName == other.lastName);
    }

    // Print method
    void print() const {
        cout << "Name: " << firstName << " " << lastName << "\n"
             << "Relationship: " << relationship << "\n"
             << "Birthdate: " << birthDate.getMonth() << "/"
             << birthDate.getDay() << "/" << birthDate.getYear() << "\n"
             << "Address: " << streetAddress << ", " 
             << city << ", " 
             << state << " " 
             << zipCode << "\n"
             << "Phone: " << phoneNumber << endl;
    }

    // Overloaded operator<< to print extPersonType
    friend ostream& operator<<(ostream& os, const extPersonType& person) {
        os << "Name: " << person.getFirstName() << " " << person.getLastName() << "\n"
           << "Relationship: " << person.getRelationship() << "\n"
           << "Birthdate: " << person.getBirthDate().getMonth() << "/"
           << person.getBirthDate().getDay() << "/" << person.getBirthDate().getYear() << "\n"
           << "Address: " << person.getStreetAddress() << ", " 
           << person.getCity() << ", " 
           << person.getState() << " " 
           << person.getZipCode() << "\n"
           << "Phone: " << person.getPhoneNumber();
        return os;
    }
};
