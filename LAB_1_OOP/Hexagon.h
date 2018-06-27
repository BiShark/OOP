#ifndef HEXAGON_H
#define HEXAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(std::istream& is);
    Hexagon(double side);
    Hexagon(const Hexagon& orig);
    double Square() override;
    void   Print()  override;
    virtual ~Hexagon();
    
private:
    double side;
};

#endif /*  Hexagon_H  */