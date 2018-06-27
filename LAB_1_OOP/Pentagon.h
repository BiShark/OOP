#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure{
public:
    Pentagon();
    Pentagon(std::istream& is);
    Pentagon(double side);
    Pentagon(const Pentagon& orig);
    double Square() override;
    void Print() override;
    virtual ~Pentagon();

private:
    double side;
};

#endif  /* TRIANGLE_H */