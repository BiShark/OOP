#include <cmath>
#include <cstring>
#include <iostream>
#include "Pentagon.h"

#define PI 3.14159265

Pentagon::Pentagon() : Pentagon(0) {
}

Pentagon::Pentagon(size_t s): side(s) {
    //std::cout << "Pentagon created: " << side << std::endl;
}

Pentagon::Pentagon(std::istream& is) {
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Pentagon::Pentagon(const Pentagon& orig) {
    //std::cout << "Pentagon copy created" << std::endl;
    side = orig.side;
}

size_t Pentagon::Square() {
    return (double)(5 * side * side / (4 * (double)tan(36 * (PI / 180))));
}

void Pentagon::Print() {
    std::cout << "Side =  " << side << std::endl;
}

Pentagon::~Pentagon() {
    //std::cout << "Pentagon: deleted " << std::endl;
}

Pentagon& Pentagon::operator=(const Pentagon& right) {
    if (this == &right)
        return *this;
    side = right.side;
    return *this;
}

Pentagon& Pentagon::operator++() {
    side++;
    return *this;
}

Pentagon operator+(const Pentagon& left, const Pentagon& right) {
    return Pentagon(left.side + right.side);
}


bool operator==(const Pentagon& left, const Pentagon& right) {
    return (left.side == right.side);
}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
    os << "a = " << obj.side << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& obj) {
    is >> obj.side;
    return is;
}