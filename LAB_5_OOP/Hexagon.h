#ifndef HEXAGON_H
#define HEXAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Hexagon : public Figure {
public:
	Hexagon& operator++();
    friend Hexagon operator+(const Hexagon& left,const Hexagon& right);
    friend bool operator==(const Hexagon& left, const Hexagon& right);
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
    friend std::istream& operator>>(std::istream& is, Hexagon& obj);
    Hexagon& operator=(const Hexagon& right);
    Hexagon();
    Hexagon(std::istream& is);
    Hexagon(size_t side);
    Hexagon(const Hexagon& orig);
    size_t Square() override;
    void   Print()  override;
    virtual ~Hexagon();
private:
    size_t side;
};

#endif /*  Hexagon_H  */