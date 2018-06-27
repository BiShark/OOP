#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure{
public:
	Pentagon& operator++();
    friend Pentagon operator+(const Pentagon& left,const Pentagon& right);
    friend bool operator==(const Pentagon& left, const Pentagon& right);
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& is, Pentagon& obj);
    Pentagon& operator=(const Pentagon& right);
    Pentagon();
    Pentagon(std::istream& is);
    Pentagon(size_t side);
    Pentagon(const Pentagon& orig);
    size_t Square() override;
    void Print() override;
    virtual ~Pentagon();
private:
    size_t side;
};

#endif  /* TRIANGLE_H */