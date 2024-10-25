#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>
#include "dateType.h"
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include "linkedList.h"

using namespace std; 

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType() {}

    void addEntry(const extPersonType& newPerson) {
        insert(newPerson);
    }

    void addNewEntry() {
        string fName, lName, rel, street, city, state, zip, phone;
        int month, day, year;

        // Get user input
        cout << "Enter first name: ";
        cin >> fName;
        cout << "Enter last name: ";
        cin >> lName;
        cout << "Enter relationship: ";
        cin >> rel;
        cout << "Enter birthdate (month day year): ";
        cin >> month >> day >> year;
        cout << "Enter street address: ";
        cin.ignore(); // Clear newline from input buffer
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter state: ";
        getline(cin, state);
        cout << "Enter zip code: ";
        getline(cin, zip);
        cout << "Enter phone number: ";
        getline(cin, phone);

        try {
            dateType birthDate(month, day, year);
            extPersonType newPerson(fName, lName, rel, birthDate, street, city, state, zip, phone);
            addEntry(newPerson);
            cout << "New entry added successfully." << endl;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void deleteEntry() {
        string fName, lName;
        cout << "Enter first name of the entry to delete: ";
        cin >> fName;
        cout << "Enter last name of the entry to delete: ";
        cin >> lName;

        extPersonType searchPerson(fName, lName, "", dateType(), "", "", "", "", "");
        deleteNode(searchPerson);
    }

    bool findPerson(const string& firstName, const string& lastName) const {
        nodeType<extPersonType>* current = this->first; // Start from the first node
        while (current != nullptr) {
            if (current->info.getFirstName() == firstName && current->info.getLastName() == lastName) {
                return true; // Person found
            }
            current = current->link; // Move to the next node
        }
        return false; // Person not found
    }

    // Method to find all relations of a given relationship type
    void findRelations(const string& relationship) const {
        nodeType<extPersonType>* current = this->first; // Start from the first node
        bool found = false;

        while (current != nullptr) {
            if (current->info.getRelationship() == relationship) {
                current->info.print(); // Print the person if the relationship matches
                found = true;
            }
            current = current->link; // Move to the next node
        }

        if (!found) {
            cout << "No entries found with the relationship: " << relationship << endl;
        }
    }

    void saveToFile() {
        ofstream outfile("AddressData.txt");
        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            outfile << current->info.getFirstName() << " "
                    << current->info.getLastName() << " "
                    << current->info.getRelationship() << " "
                    << current->info.getBirthDate().getMonth() << " "
                    << current->info.getBirthDate().getDay() << " "
                    << current->info.getBirthDate().getYear() << " "
                    << current->info.getStreetAddress() << " "
                    << current->info.getCity() << " "
                    << current->info.getState() << " "
                    << current->info.getZipCode() << " "
                    << current->info.getPhoneNumber() << endl;
            current = current->link;
        }
        outfile.close();
        cout << "Address book saved successfully." << endl;
    }

    void initEntry(const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string fName, lName, rel;
        int month, day, year;
        string streetAddress, city, state, zipCode, phoneNumber;

        while (infile >> fName >> lName >> month >> day >> year) {
            if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900) {
                cerr << "Invalid date for " << fName << " " << lName << endl;
                infile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Skip invalid entries
            }
            infile.ignore(); // Ignore the newline after year
            getline(infile, streetAddress);
            getline(infile, city);
            getline(infile, state);
            getline(infile, zipCode);
            getline(infile, phoneNumber);
            getline(infile, rel);

            dateType birthDate(month, day, year);
            extPersonType newPerson(fName, lName, rel, birthDate, streetAddress, city, state, zipCode, phoneNumber);
            addEntry(newPerson);
        }

        infile.close();
        cout << "File reading complete." << endl;
    }

    void printEntries() const {
        if (this->isEmpty()) { // Use this-> to refer to the base class function
            cout << "Address book is empty." << endl;
            return;
        }

        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            current->info.print();
            current = current->link;
        }
    }
};
