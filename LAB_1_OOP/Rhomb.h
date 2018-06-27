#ifndef RHOMB_H
#define RHOMB_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rhomb : public Figure
{
public:
    Rhomb();
    Rhomb(std::istream &is);
    Rhomb(double side, int angle);
    Rhomb(const Rhomb& orig);

    double Square() override;
    void Print() override;
    virtual ~Rhomb();

private:
    double side;
    int angle;
};

#endif  /* RHOMB_H */