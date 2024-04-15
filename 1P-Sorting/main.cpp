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
  vector<int> ks = {2, 3, 5, 10, 50, 100, 200};
  ofstream out("output.txt");

  for (int k : ks) {
    random_shuffle(toSort.begin(), toSort.end());

    auto start = chrono::high_resolution_clock::now();
    sorter(toSort, k);
    auto end = chrono::high_resolution_clock::now();
    auto time = end - start;

    out << k << " " << time.count() / 1e9 << endl;
  }
  return 0;

  // int n = 100000;
  // vector<int> toSort(n);
  // vector<int> ks = {2, 3, 5, 10, 50, 100, 200};
  // vector<int> ns = {1 * n, 2 * n, 3 * n, 4 * n, 5 * n,
  //                   6 * n, 7 * n, 8 * n, 9 * n, 10 * n};
  // ofstream out("output.txt");

  // for (int n1 : ns) {
  //   toSort.resize(n1);
  //   for (int i = 0; i < n1; i++) {
  //     toSort[i] = i;
  //   }
  //   random_shuffle(toSort.begin(), toSort.end());

  //   auto start = chrono::high_resolution_clock::now();
  //   sorter(toSort, 3);
  //   auto end = chrono::high_resolution_clock::now();
  //   auto time = end - start;

  //   out << n1 << " " << time.count() / 1e9 << endl;
  // }
  // return 0;
}
