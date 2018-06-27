
#ifndef RHOMB_H
#define RHOMB_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"


class Rhomb : public Figure {
public:
    Rhomb& operator++();
    friend Rhomb operator+(const Rhomb& left,const Rhomb& right);
    friend bool operator==(const Rhomb& left, const Rhomb& right);
    friend std::ostream& operator<<(std::ostream& os, const Rhomb& obj);
    friend std::istream& operator>>(std::istream& is, Rhomb& obj);
    Rhomb& operator=(const Rhomb& right);
	Rhomb();
	Rhomb(std::istream &is);
	Rhomb(size_t side, size_t angle);
	Rhomb(const Rhomb& orig);
	size_t Square() override;
	void Print() override;
	virtual ~Rhomb();
private:
    size_t side;
    size_t angle;
};
#endif /* RECTANGLE_H */ 