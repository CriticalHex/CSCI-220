/*
 * main.cpp
 *
 * Includes the main() function for the sorting project.
 *
 * This code is included in the build target "run-main"
 */

#include <chrono>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>

#include "sorter.h"

using namespace std;

int main() {
  int n = 100000;
  vector<int> toSort(n);
  for (int i = 0; i < n; i++) {
    toSort[i] = i;
  }
  vector<int> ks = {2, 3, 5, 10, 50, 100, 200, 20000, 100000, 200000};
  ofstream out("output.txt");

  for (int k : ks) {
    random_shuffle(toSort.begin(), toSort.end());

    auto start = chrono::high_resolution_clock::now();
    sorter(toSort, 2);
    auto end = chrono::high_resolution_clock::now();
    auto time = end - start;

    out << k << " " << time.count() / 1e9 << endl;
  }
  return 0;
}
