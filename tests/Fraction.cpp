#include "Fraction.h"

// big 3
fraction::fraction(const fraction &orig) {
  this->~fraction();
  num = new int(*orig.num);
  den = new int(*orig.den);
}
fraction &fraction::operator=(const fraction &orig) {
  this->~fraction();
  num = new int(*orig.num);
  den = new int(*orig.den);
  return *this;
}
fraction::~fraction() {
  delete num;
  delete den;
  num = den = nullptr;
}
// arithmetic operations
fraction fraction::operator+(const fraction &rhs) {
  fraction n(*this);
  if (*n.den != *rhs.den) {
    *n.den *= *rhs.den;
    *n.num = *n.num * *rhs.den + *rhs.num * *n.den;
  } else {
    *n.num += *rhs.num;
  }
  return n;
}

std::ostream &operator<<(std::ostream &out, const fraction &f) {
  out << *f.num << "/" << *f.den << std::endl;
  return out;
}