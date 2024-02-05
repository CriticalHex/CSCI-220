/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 */

#include "stack-stage1.h"

using namespace std;

string stack::top() {
  return _data[_size - 1];
}

bool stack::is_empty() {
  return _size == 0;
}

void stack::push(const string &it) {
  if (_size == _alloc_size) {
    _alloc_size *= 2;
    string *data = new string[_alloc_size];
    copy(_data, _data + _size, data);
    delete[] _data;
    _data = data;
  }
  _data[_size] = it;
  _size++;
}

void stack::pop() {
  _size--;
}

size_t stack::size() {
  return _size;
}

stack::stack() {}
stack::~stack() {
  delete[] _data;
  _data = nullptr;
}
