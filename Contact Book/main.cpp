#include "contactbooks.h"
#include "person.h"
#include "address.h"

int main() {
    ContactBook contactBook;
    int choice;

    do {
        std::cout << "\nContact Book Menu:\n"
                  << "1. Add Contact\n"
                  << "2. Display All Contacts\n"
                  << "3. Search Contact by Last Name\n"
                  << "4. Search Contact by Classification\n"
                  << "5. Display Favorite Contacts\n"
                  << "6. Reverse Contact Order\n"
                  << "7. Delete Contact by Last Name\n"
                  << "8. Save Contacts to File\n"
                  << "9. Load Contacts from File\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string firstName, lastName, phoneNumber, email, classification;
                bool isFavorite;
                std::string street, city, country, zip;

                std::cout << "Enter First Name: ";
                std::cin >> firstName;
                std::cout << "Enter Last Name: ";
                std::cin >> lastName;
                std::cout << "Enter Phone Number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter Email: ";
                std::cin >> email;
                std::cout << "Enter Classification: ";
                std::cin >> classification;
                std::cout << "Is this a favorite contact? (1 for Yes, 0 for No): ";
                std::cin >> isFavorite;

                std::cout << "Enter Street: ";
                std::cin >> street;
                std::cout << "Enter City: ";
                std::cin >> city;
                std::cout << "Enter Country: ";
                std::cin >> country;
                std::cout << "Enter ZIP Code: ";
                std::cin >> zip;

                Address address(street, city, country, zip);
                Person newPerson(1, firstName, lastName, phoneNumber, email, classification, isFavorite, &address);
                contactBook.addContact(newPerson);

                std::cout << "Contact added successfully!\n";
                break;
            }
            case 2:
                contactBook.printAllContacts();
                break;
            case 3: {
                std::string lastName;
                std::cout << "Enter Last Name to search: ";
                std::cin >> lastName;
                contactBook.searchByLastName(lastName);
                break;
            }
            case 4: {
                std::string classification;
                std::cout << "Enter Classification to search: ";
                std::cin >> classification;
                contactBook.searchByClassification(classification);
                break;
            }
            case 5:
                contactBook.printFavContacts();
                break;
            case 6:
                contactBook.reverseContacts();
                std::cout << "Contacts reversed.\n";
                break;
            case 7: {
                std::string lastName;
                std::cout << "Enter Last Name of contact to delete: ";
                std::cin >> lastName;
                contactBook.deleteContact(lastName);
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename to save contacts: ";
                std::cin >> filename;
                contactBook.saveContactsToFile(filename);
                break;
            }
            case 9: {
                std::string filename;
                std::cout << "Enter filename to load contacts: ";
                std::cin >> filename;
                contactBook.loadContactsFromFile(filename);
                break;
            }
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
