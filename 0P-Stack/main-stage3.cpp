/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include "stack-stage3.h"
#include <chrono>
#include <iostream>

using namespace std;

double time_n_pushes(unsigned n) {
  stack<unsigned> s;
  auto start_time = chrono::system_clock::now();
  // do the n pushes
  for (unsigned i = 0; i < n; i++) {
    s.push(i);
  }
  auto stop_time = chrono::system_clock::now();
  chrono::duration<double> elapsed = stop_time - start_time;
  return elapsed.count();
}

int main() {
  // You can use this main() to run your own analysis or initial testing code.
  const int runs = 10;
  double arr[runs];
  double num;
  for (int times = 0; times < runs; times++) {
    for (size_t i = 1; i <= 10; i++) {
      num = time_n_pushes(i * 10000);
      //   cout << i << ": " << num << endl;
      arr[i] += num;
    }
  }
  for (size_t i = 1; i <= 10; i++) {
    cout << i * 10000 << ": " << arr[i] / runs << endl;
  }

  return 0;
}
