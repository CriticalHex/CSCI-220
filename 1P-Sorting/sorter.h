/*
 * sorter.h
 *
 * Declares a template function:
 *
 *   sorter() : k-way merge sort.
 *
 *
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 *
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int UINT;

template <class T> void pVec(vector<T> &vec) {
  for (auto k : vec) {
    cout << k << ", ";
  }
  cout << endl;
}

template <class T> void pVecVec(vector<vector<T>> &vec) {
  for (auto v : vec) {
    for (auto k : v) {
      cout << k << ", ";
    }
    cout << endl;
  }
}

template <class T> void sorter(vector<T> &vec, UINT k) {
  if (vec.size() == 0 || vec.size() == 1 || k == 0)
    return;
  // split
  vector<vector<T>> vectors(k);
  UINT b = 0;
  for (UINT i = 0; i < vec.size(); i++) {
    vectors[b % k].push_back(vec[i]);
    b++;
  }
  for (UINT i = 0; i < k; i++) {
    sorter(vectors[i], k);
  }
  // merge
  vector<T> merged;
  T largest = *max_element(vec.begin(), vec.end());
  if (vec.size() > k) {
    vector<UINT> indexes(k);
    UINT idx;
    T smallest;
    int sIndex, lIndex;
    for (UINT i = 0; i < vec.size(); i++) {
      smallest = largest;
      sIndex = lIndex = -1;
      for (UINT v = 0; v < k; v++) {
        idx = indexes[v];
        if (vectors[v].size() > idx) {
          if (lIndex == -1 && vectors[v][idx] == largest)
            lIndex = v;
          else if (vectors[v][idx] < smallest) {
            smallest = vectors[v][idx];
            sIndex = v;
          }
        }
      }
      if (sIndex != -1)
        indexes[sIndex]++;
      else
        indexes[lIndex]++;
      merged.push_back(smallest);
    }
  } else {
    vector<T> expanded;
    for (vector<T> v : vectors) {
      for (T t : v) {
        expanded.push_back(t);
      }
    }
    for (UINT i = 0; i < vec.size(); i++) {
      auto iter = min_element(expanded.begin(), expanded.end());
      merged.push_back(*iter);
      *iter = largest;
    }
  }
  copy(merged.begin(), merged.end(), vec.begin());
}
#endif
