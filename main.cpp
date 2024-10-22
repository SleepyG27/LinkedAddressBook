#include <iostream>
#include <fstream>
#include <sstream>
#include "dateType.h"
#include "addressType.h"
#include "extPersonType.h"
#include <vector>


using namespace std;

vector<extPersonType> readAddressBook(const string& filename) {
    ifstream inFile(filename);
    vector<extPersonType> addressBook;

    if (!inFile) {
        cout << "Error opening file: " << filename << endl;
        return addressBook;
    }

    string line;
    while (getline(inFile, line)) {
        string firstName, lastName, street, city, state, phoneNumber, relationship;
        int month, day, year, zipCode;

        // Read name
        istringstream nameStream(line);
        nameStream >> firstName >> lastName;

        // Read birth date
        getline(inFile, line);
        istringstream dateStream(line);
        dateStream >> month >> day >> year;

        // Read address
        getline(inFile, street);
        getline(inFile, city);
        getline(inFile, state);
        inFile >> zipCode;
        inFile.ignore(); // Ignore the newline after zip code

        // Read phone number
        getline(inFile, phoneNumber);

        // Read relationship
        getline(inFile, relationship);

        // Create dateType and addressType instances
        dateType birthDate(month, day, year);
        addressType address(street, city, state, zipCode);

        // Create extPersonType instance with names
        extPersonType person(firstName, lastName, birthDate, address, phoneNumber, relationship);
        addressBook.push_back(person);
    }

    inFile.close();
    return addressBook;
}

int main() {
    vector<extPersonType> addressBook = readAddressBook("AddressBookData.txt");

    for (const auto& person : addressBook) {
        person.printInfo();
        std::cout << std::endl; // Add a line break between entries
    }

    return 0;
}
