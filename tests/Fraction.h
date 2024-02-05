#ifndef FRAC_H
#define FRAC_H

#include <iostream>

class fraction {
private:
  int *num = nullptr;
  int *den = nullptr;

public:
  // constructor
  fraction(int n, int d = 1) {
    num = new int(n);
    den = new int(d);
  }
  // big 3
  fraction(const fraction &orig);
  fraction &operator=(const fraction &orig);
  ~fraction();
  // arithmetic operations
  fraction        operator+(const fraction &rhs);
  friend fraction operator*(const fraction &lhs, const fraction &rhs) {
    fraction n(lhs);
    *n.den *= *rhs.den;
    *n.num *= *rhs.num;
    return n;
  }
  // printing
  friend std::ostream &operator<<(std::ostream &out, fraction &frac);
};

#endif