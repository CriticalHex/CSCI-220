/*
Lukas' Code :P
*/

#ifndef _SORTER_H
#define _SORTER_H

#include <algorithm>
#include <cstddef>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template <class T>
bool compareVectors(const vector<T> &v1, const vector<T> &v2) {
  return v1.size() > v2.size(); // Sort in descending order of vector sizes
}

template <class T>
queue<vector<T>> sortVectorsBySize(const vector<vector<T>> &input) {
  // Create a priority queue with a custom comparator
  auto comp = [](const vector<T> &v1, const vector<T> &v2) {
    return v1.size() > v2.size(); // Sort in descending order of vector sizes
  };
  priority_queue<vector<T>, vector<vector<T>>, decltype(comp)> pq(comp);

  // Insert vectors into the priority queue
  for (const auto &vec : input) {
    pq.push(vec);
  }

  // Extract vectors from the priority queue into a new queue
  queue<vector<T>> sortedQueue;
  while (!pq.empty()) {
    sortedQueue.push(pq.top());
    pq.pop();
  }

  return sortedQueue;
}

template <class T>
vector<T> mergeSortedVectors(const vector<T> &vec1, const vector<T> &vec2) {
  vector<T> merged;
  merged.reserve(vec1.size() + vec2.size());

  auto it1 = vec1.begin();
  auto it2 = vec2.begin();

  // Merge the two sorted vectors
  while (it1 != vec1.end() && it2 != vec2.end()) {
    if (*it1 < *it2) {
      merged.push_back(*it1);
      ++it1;
    } else {
      merged.push_back(*it2);
      ++it2;
    }
  }

  // Copy the remaining elements from vec1 (if any)
  while (it1 != vec1.end()) {
    merged.push_back(*it1);
    ++it1;
  }

  // Copy the remaining elements from vec2 (if any)
  while (it2 != vec2.end()) {
    merged.push_back(*it2);
    ++it2;
  }

  return merged;
}

template <class T> vector<T> improved_merge(vector<vector<T>> &vecs) {
  queue<vector<T>> q = sortVectorsBySize(vecs);
  while (q.size() > 1) {
    vector<T> vec1 = q.front();
    q.pop();
    vector<T> vec2 = q.front();
    q.pop();

    vector<T> merged = mergeSortedVectors(vec1, vec2);
    q.push(merged);
  }
  return q.front();
}

template <class T> void sorter(vector<T> &vec, size_t k) {
  if (vec.size() <= 1) {
    return;
  }

  if (k > vec.size())
    k = vec.size();
  /// K way split
  vector<vector<T>> vecs(k);

  for (size_t i = 0; i < vec.size(); i++) {
    // PERF: maybe make the vecs the correct size upfront? (reduce the times it
    // re-sizes)
    vecs.at(i % k).push_back(vec.at(i));
  }

  // for  all i in [1..K]
  //	kWayMergeSort(a_i, K)
  // merge parts

  for (auto &a_i : vecs) {
    sorter(a_i, k);
  }

  // vec = improved_merge(vecs);

  for (size_t i = 0; i < vec.size(); i++) {
    T max;
    int m = 0;
    for (size_t starter = 0; starter < vecs.size(); starter++) {
      if (vecs.at(starter).size() > 0) {
        max = vecs.at(starter).back();
        m = starter;
        break;
      }
    }

    for (size_t j = m + 1; j < vecs.size(); j++) {
      if (vecs.at(j).size() == 0) {
        continue;
      }
      T lookup = vecs.at(j).back();
      if (lookup > max) {
        max = lookup;
        m = (int)j;
      }
    }
    vec.at(vec.size() - i - 1) = max;
    vecs.at(m).pop_back();
  }
}
#endif

// MY GARBAGE CODE BELOW!

// #ifndef _SORTER_H
// #define _SORTER_H

// #include <algorithm>
// #include <cmath>
// #include <cstddef>
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;
// typedef unsigned int UINT;

// template <class T> void pVec(vector<T> &vec) {
//   for (auto k : vec) {
//     cout << k << ", ";
//   }
//   cout << endl;
// }

// template <class T> void pVecVec(vector<vector<T>> &vec) {
//   for (auto v : vec) {
//     for (auto k : v) {
//       cout << k << ", ";
//     }
//     cout << endl;
//   }
// }

// template <class T> void sorter(vector<T> &vec, UINT k) {
//   if (vec.size() == 0 || vec.size() == 1 || k == 0)
//     return;
//   // split
//   vector<vector<T>> vectors(k);
//   UINT b = 0;
//   for (UINT i = 0; i < vec.size(); i++) {
//     vectors[b % k].push_back(vec[i]);
//     b++;
//   }
//   for (UINT i = 0; i < k; i++) {
//     sorter(vectors[i], k);
//   }
//   // merge
//   vector<T> merged;
//   T largest = *max_element(vec.begin(), vec.end());
//   if (vec.size() > k) {
//     vector<UINT> indexes(k);
//     UINT idx;
//     T smallest;
//     int sIndex, lIndex;
//     for (UINT i = 0; i < vec.size(); i++) {
//       smallest = largest;
//       sIndex = lIndex = -1;
//       for (UINT v = 0; v < k; v++) {
//         idx = indexes[v];
//         if (vectors[v].size() > idx) {
//           if (lIndex == -1 && vectors[v][idx] == largest)
//             lIndex = v;
//           else if (vectors[v][idx] < smallest) {
//             smallest = vectors[v][idx];
//             sIndex = v;
//           }
//         }
//       }
//       if (sIndex != -1)
//         indexes[sIndex]++;
//       else
//         indexes[lIndex]++;
//       merged.push_back(smallest);
//     }
//   } else {
//     vector<T> expanded;
//     for (vector<T> v : vectors) {
//       for (T t : v) {
//         expanded.push_back(t);
//       }
//     }
//     for (UINT i = 0; i < vec.size(); i++) {
//       auto iter = min_element(expanded.begin(), expanded.end());
//       merged.push_back(*iter);
//       *iter = largest;
//     }
//   }
//   copy(merged.begin(), merged.end(), vec.begin());
// }
// #endif
