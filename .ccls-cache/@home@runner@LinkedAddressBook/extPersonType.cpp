#include "extPersonType.h"

// Constructor
extPersonType::extPersonType(const std::string& firstName, const std::string& lastName,
                             const dateType& birthDate, const addressType& address,
                             const std::string& phoneNumber, const std::string& relationship)
    : birthDate(birthDate), address(address), phoneNumber(phoneNumber),
      relationship(relationship), firstName(firstName), lastName(lastName) {}

// Function to print the person's information
void extPersonType::printInfo() const {
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Birth Date: ";
    birthDate.print(); // Ensure the date prints correctly
    std::cout << std::endl;
    std::cout << "Address: ";
    address.print(); // Assume you have a print function in addressType
    std::cout << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}
