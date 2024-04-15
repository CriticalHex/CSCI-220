/*
 * main.cpp
 *
 * Includes the main() function for the hashtable project.
 *
 * This code is included in the default build target.  It
 * produces the program run-main.
 */

#include <fstream>
#include <iostream>
#include <string>

#include "hash_functions.h"
#include "hashtable.h"

#include "random220.h"

using namespace std;

const int W = 172823;

template <typename H>
void experiment(const int M, vector<string> &words, string fname) {
  hashtable<string, H> t;
  vector<string> w;

  const float p = 2 * M / float(W);
  for (auto s : words) {
    if (bernoulli(p)) {
      w.push_back(s);
      if (bernoulli(0.5)) {
        t.insert(s);
      }
    }
  }
  int tests = 0;
  int comps = 0;
  const float prob = 1000.f / w.size();
  for (auto s : w) {
    if (bernoulli(prob)) {
      tests++;
      comps += t.count_comparisons(s);
    }
  }
  ofstream out(fname, ios_base::app);
  // cout << t.size() << "," << comps / float(tests) << endl;
  out << t.size() << "," << comps / float(tests) << endl;
  out.close();
}

int main() {
  seed_now();
  ifstream in("dictionary.txt");
  string s;
  vector<string> w;
  while (in >> s) {
    w.push_back(s);
  }
  for (int i = 0; i < 300; i++) {
    experiment<hash0>(equalikely(1000, W / 2), w, "hash0.txt");
  }
  for (int i = 0; i < 300; i++) {
    experiment<hash1>(equalikely(1000, W / 2), w, "hash1.txt");
  }
  for (int i = 0; i < 300; i++) {
    experiment<hash2>(equalikely(1000, W / 2), w, "hash2.txt");
  }
  for (int i = 0; i < 300; i++) {
    experiment<hash3>(equalikely(1000, W / 2), w, "hash3.txt");
  }
  for (int i = 0; i < 300; i++) {
    experiment<hash4>(equalikely(1000, W / 2), w, "hash4.txt");
  }

  // You can use this main() to run your own analysis or testing code.
  // cout << "If you are seeing this, you have successfully run main!" << endl;

  // ==================================================================
  // The code below this point is relevant for the analysis part of the
  // hashtable project.  You do not need it for the programming part.
  // ==================================================================

  // The code below illustrates how to use the provided hash function
  // "functional" objects, and lets you see the different hash values
  // produced by each.
  //   hash0 h0;
  //   hash1 h1;
  //   hash2 h2;
  //   hash3 h3;
  //   hash4 h4;

  //   string s("Hello");
  //   cout << h0(s) << endl;
  //   cout << h1(s) << endl;
  //   cout << h2(s) << endl;
  //   cout << h3(s) << endl;
  //   cout << h4(s) << endl;

  // Here's how you create a hashtable to use a particular hash function:
  //   hashtable<string, hash1> ht;
  //   ht.insert(s);
}
