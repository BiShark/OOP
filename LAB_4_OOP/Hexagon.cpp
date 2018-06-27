#include "Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {
}

Hexagon::Hexagon(size_t s): side(s) {
    //std::cout << "Hexagon created: " << side << std::endl;
}

Hexagon::Hexagon(std::istream& is) {
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Hexagon::Hexagon(const Hexagon& orig) {
    //std::cout << "Hexagon copy created" << std::endl;
    side = orig.side;
}


size_t Hexagon::Square() {
    return size_t((6.0 * side * side) / (4.0 * tan(M_PI / 6.0)));
}

void Hexagon::Print() {
    std::cout << "Sides =  " << side << std::endl;
}

Hexagon::~Hexagon() {
    //std::cout << "Hexagon: deleted " << std::endl;
}

Hexagon& Hexagon::operator=(const Hexagon& right) {
    if (this == &right)
        return *this;
    side = right.side;
    return *this;
}

Hexagon& Hexagon::operator++() {
    side++;
    return *this;
}

Hexagon operator+(const Hexagon& left, const Hexagon& right) {
    return Hexagon(left.side + right.side);
}


bool operator==(const Hexagon& left, const Hexagon& right) {
    return (left.side == right.side);
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
    os << "a = " << obj.side << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Hexagon& obj) {
    is >> obj.side;
    return is;
}