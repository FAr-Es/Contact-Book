#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "person.h"
#include "Darray.h"
#include <fstream>

class ContactBook {
private:
    Darray<Person> contacts;

public:
    void addContact(const Person& person) {
        contacts.append(person);
    }

    void printAllContacts() const {
        std::cout << std::left << std::setw(5) << "ID" << std::setw(15) << "Name"
                  << std::setw(15) << "Phone" << std::setw(15) << "Classification"
                  << std::setw(10) << "Favorite" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        for (size_t i = 0; i < contacts.getSize(); i++) {
            std::cout << std::setw(5) << (i + 1);
            contacts.get(i).display();
            std::cout << "-------------------" << std::endl;
        }
    }

    void searchByLastName(const std::string& lastName) const {
        bool found = false;
        for (size_t i = 0; i < contacts.getSize(); i++) {
            if (contacts.get(i).getLastName() == lastName) {
                contacts.get(i).display();
                found = true;
            }
        }
        if (!found) std::cout << "Contact not found." << std::endl;
    }

    void searchByClassification(const std::string& classification) const {
        bool found = false;
        for (size_t i = 0; i < contacts.getSize(); i++) {
            if (contacts.get(i).getClassification() == classification) {
                contacts.get(i).display();
                found = true;
            }
        }
        if (!found) std::cout << "No contacts with classification: " << classification << std::endl;
    }

    void printFavContacts() const {
        bool found = false;
        for (size_t i = 0; i < contacts.getSize(); i++) {
            if (contacts.get(i).getFavorite()) {
                contacts.get(i).display();
                found = true;
            }
        }
        if (!found) std::cout << "No favorite contacts." << std::endl;
    }

    void reverseContacts() {
        contacts.reverse();
    }

    void deleteContact(const std::string& lastName) {
        for (size_t i = 0; i < contacts.getSize(); i++) {
            if (contacts.get(i).getLastName() == lastName) {
                contacts.erase(i);
                std::cout << "Contact deleted." << std::endl;
                return;
            }
        }
        std::cout << "Contact not found." << std::endl;
    }

    void saveContactsToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Failed to open file for saving.\n";
            return;
        }
        for (size_t i = 0; i < contacts.getSize(); i++) {
            outFile << contacts.get(i).getLastName() << "\n";
        }
        outFile.close();
    }

    void loadContactsFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Failed to open file for loading.\n";
            return;
        }
        inFile.close();
    }
};

#endif
