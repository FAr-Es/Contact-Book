#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

class Address {
private:
    std::string street, city, country, zip;

public:
    Address() {}
    Address(const std::string& s, const std::string& c, const std::string& cntry, const std::string& zp)
        : street(s), city(c), country(cntry), zip(zp) {}

    void display() const {
        std::cout << "Address: " << street << ", " << city << ", " << country << ", " << zip << std::endl;
    }
};

#endif
