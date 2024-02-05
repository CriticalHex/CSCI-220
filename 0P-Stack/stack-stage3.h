/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t

using namespace std;

template <typename T>
class stack {
public:
  T top() { return _data[_size - 1]; }

  void push(const T &it) {
    if (_size == _alloc_size) {
      _alloc_size *= 2;
      T *data = new T[_alloc_size];
      copy(_data, _data + _size, data);
      delete[] _data;
      _data = data;
    }
    _data[_size] = it;
    _size++;
  }

  void   pop() { _size--; }
  size_t size() { return _size; }
  bool   is_empty() { return _size == 0; }

  stack() {}
  stack(stack &other) {
    _data       = new T[other._alloc_size];
    _size       = other._size;
    _alloc_size = other._alloc_size;
    copy(other._data, other._data + other._size, _data);
  }
  stack &operator=(stack &other) {
    if (_data != other._data) {
      delete[] _data;
      _data       = new T[other._alloc_size];
      _size       = other._size;
      _alloc_size = other._alloc_size;
      copy(other._data, other._data + other._size, _data);
    }
    return *this;
  }
  ~stack() {
    delete[] _data;
    _data = nullptr;
  }

private:
  size_t _alloc_size = 1;
  T     *_data       = new T[_alloc_size];
  size_t _size       = 0;
};

#endif