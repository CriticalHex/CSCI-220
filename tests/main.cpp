#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
  fraction a(5, 8);
  fraction b(4, 9);
  fraction c = a;
  cout << (a * b) << endl; // prints 20/72
  cout << (a + b) << endl; // prints 77/72
  cout << (b * c) << endl; // prints 20/72
  a = c = b;
  cout << (a * b) << endl; // prints 16/81
  return 0;
}
