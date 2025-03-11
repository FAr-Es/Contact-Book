#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "address.h"

class Person {
private:
    size_t id;
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string classification;
    bool favorite;
    Address* address;

public:
    Person()
        : id(0), phone_number(""), first_name(""), last_name(""), email(""), classification(""), favorite(false), address(nullptr) {}

    Person(size_t i, std::string fn, std::string ln, std::string pn, std::string e, std::string classifi, bool fav, Address* addr)
        : id(i), first_name(fn), last_name(ln), phone_number(pn), email(e), classification(classifi), favorite(fav), address(addr) {}

    void setID(size_t i) { id = i; }
    void setFirstName(std::string fn) { first_name = fn; }
    void setLastName(std::string ln) { last_name = ln; }
    void setPhoneNumber(std::string pn) { phone_number = pn; }
    void setEmail(std::string e) { email = e; }
    void setClassification(std::string classifi) { classification = classifi; }
    void setFavorite(bool fav) { favorite = fav; }
    void setAddress(Address* addr) { address = addr; }

    size_t getID() const { return id; }
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getEmail() const { return email; }
    std::string getClassification() const { return classification; }
    bool getFavorite() const { return favorite; }
    Address* getAddress() const { return address; }

    void display() const {
        std::cout << "Name: " << first_name << " " << last_name
                  << "\nPhone: " << phone_number << "\nEmail: " << email
                  << "\nClassification: " << classification
                  << "\nFavorite: " << (favorite ? "Yes" : "No") << "\n";
        if (address) {
            address->display();
        } else {
            std::cout << "No address available." << std::endl;
        }
    }
};

#endif
