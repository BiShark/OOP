#include <iostream>
#include <cmath>
#include "Rhomb.h"

#define PI 3.14159265

Rhomb::Rhomb() : Rhomb(0, 0) {
}

Rhomb::Rhomb(double s, int ang): side(s), angle(ang) {
    if (angle > 180) {
        angle %= 180;
    }
    if (angle > 90) {
        angle = 180 - angle;
    }
    std::cout << "Rhomb created: " << side << ", " << angle << std::endl;
}

Rhomb::Rhomb(std::istream &is) {
    is >> side;
    is >> angle;
    if (angle > 90 && angle < 180) {
        angle = 180 - angle;
    }
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    if(angle < 0 || angle > 180) {
        std::cerr << "Error: angles should be > 0 and < 180." << std::endl;
    }
}

Rhomb::Rhomb(const Rhomb& orig) {
    std::cout << "Rhomb copy created" << std::endl;
    side = orig.side;
    angle = orig.angle;
}

double Rhomb::Square() {
    return (double)(side * side * (double)sin(angle * (PI / 180)));
}

void Rhomb::Print() {
    std::cout << "Side = " << side << ", angle = " << angle << std::endl;
}

Rhomb::~Rhomb() {
    std::cout << "Rhomb: deleted " << std::endl;
}