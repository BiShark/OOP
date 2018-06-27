#include "Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {
}

Hexagon::Hexagon(double s): side(s) {
    std::cout << "Hexagon created: " << side << std::endl;
}

Hexagon::Hexagon(std::istream& is) {
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Hexagon::Hexagon(const Hexagon& orig) {
    std::cout << "Hexagon copy created" << std::endl;
    side = orig.side;
}


double Hexagon::Square() {
    std::cout << "Hexagon: square: ";
    return double((6.0 * side * side) / (4.0 * tan(M_PI / 6.0)));
}

void Hexagon::Print() {
    std::cout << "Sides =  " << side << std::endl;
}

Hexagon::~Hexagon() {
    std::cout << "Hexagon: deleted " << std::endl;
}