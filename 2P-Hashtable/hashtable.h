/*
 * hashtable.h
 *
 * A basic hashtable implementation.  This hashtable uses vectors,
 * rather than linked lists, to implement chaining.
 *
 * Author: <your name here>
 */

#ifndef _HASHTABLE_PROJECT_H
#define _HASHTABLE_PROJECT_H

#include <algorithm>
#include <functional> // for std::hash
#include <iostream>
#include <vector>

using namespace std;

template <class T, class H = std::hash<T>> class hashtable {
public:
  // constructor
  hashtable();

  // basic hashset operations
  void insert(const T &key);
  void resize();
  void remove(const T &key);
  bool contains(const T &key);
  size_t size();

  // diagnostic functions
  double load_factor();
  void print();

  // convenience method, invokes the "hash" template parameter
  // function object to get a hash code
  static size_t hash(const T &key) {
    H h;
    return h(key);
  }

private:
  size_t _size;
  vector<vector<T>> *_buckets = nullptr;
};

template <class T, class H> hashtable<T, H>::hashtable() {
  _buckets = new vector<vector<T>>(4);
  _size = 0;
}

template <class T, class H> void hashtable<T, H>::insert(const T &key) {
  size_t h = hash(key);
  vector<T> *index = &_buckets->at(h % _buckets->size());
  if (find(index->begin(), index->end(), key) == index->end()) {
    index->push_back(key);
    _size++;
    if (load_factor() > .75) {
      resize();
    }
  }
}

template <class T, class H> void hashtable<T, H>::resize() {
  vector<vector<T>> *newbuckets = new vector<vector<T>>(_buckets->size() * 2);
  for (auto &inner_vec : *_buckets) {
    for (const T &key : inner_vec) {
      size_t h = hash(key);
      newbuckets->at(h % newbuckets->size()).push_back(key);
    }
  }
  delete _buckets;
  _buckets = newbuckets;
}

template <class T, class H> void hashtable<T, H>::remove(const T &key) {
  size_t h = hash(key);
  vector<T> *index = &_buckets->at(h % _buckets->size());
  auto iter = find(index->begin(), index->end(), key);
  if (iter != index->end()) {
    index->erase(iter);
    _size--;
  }
}

template <class T, class H> bool hashtable<T, H>::contains(const T &key) {
  size_t h = hash(key);
  vector<T> *index = &_buckets->at(h % _buckets->size());
  return find(index->begin(), index->end(), key) != index->end();
}

template <class T, class H> size_t hashtable<T, H>::size() { return _size; }

template <class T, class H> double hashtable<T, H>::load_factor() {
  return _size / float(_buckets->size());
}

template <class T, class H> void hashtable<T, H>::print() {
  //   for (size_t index = 0; index < _buckets->size(); index++) {
  //     cout << "{ ";
  //     for (size_t key = 0; key < _buckets->at(index).size(); key++) {
  //       cout << _buckets->at(index)[key] << ", ";
  //     }
  //     cout << "}" << endl;
  //   }
}

// template <class T> void print_vec(vector<T> vec) {
//   cout << "{ ";
//   for (auto t : vec) {
//     cout << t << ", ";
//   }
//   cout << "}" << endl;
// }

#endif
