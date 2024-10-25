#include <iostream>
#include <string>
#include "addressBookType.h"

using namespace std; 

void displayMenu() {
    cout << "\n--- Address Book Menu ---" << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by relationship" << endl;
    cout << "3. Print all entries" << endl;
    cout << "4. Add an entry" << endl;
    cout << "5. Remove an entry" << endl;
    cout << "6. Save and Exit" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Initialize address book
    addressBookType myAddressBook;

    // Load data 
    string fileName = "AddressBookData.txt";
    myAddressBook.initEntry(fileName);

    bool exitProgram = false;
    int choice;

    while (!exitProgram) {
        displayMenu(); // Dislpay menu

        cin >> choice; // user options

        switch (choice) {
        case 1: {
            // Search by name
            string firstName, lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            myAddressBook.findPerson(firstName, lastName);
            break;
        }
        case 2: {
            // Search by relationship
            string relationship;
            cout << "Enter relationship: ";
            cin >> relationship;
            myAddressBook.findRelations(relationship);
            break;
        }
        case 3: {
            // Print all entries
            myAddressBook.print();
            break;
        }
        case 4: {
            myAddressBook.addNewEntry();
            break;
        }
        case 5: {
            myAddressBook.deleteEntry();
            break;
        }
        case 6: {
            myAddressBook.saveToFile();
            break; // Added break statement
        }
        case 7: {
            // Exit
            exitProgram = true;
            cout << "Exiting program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
