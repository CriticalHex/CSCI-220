#include "trie.h"
#include <iostream>

using namespace std;

trie::Node::Node() {
  isEndOfWord = false;
  for (size_t i = 0; i < 26; i++) {
    data[i] = nullptr;
  }
}

trie::trie() { head = new Node; }

trie::~trie() {}

size_t ctoi(char c) { return c - 'a'; }
char itoc(size_t i) { return i + 'a'; }

void trie::insert(const string &s) {
  Node *current = head;
  size_t i = 0;
  while (i < s.size()) {
    if (current->data[ctoi(s[i])] == nullptr)
      current->data[ctoi(s[i])] = new Node;
    current = current->data[ctoi(s[i])];
    i++;
  }
  current->isEndOfWord = true;
}

bool trie::contains(const string &s) {
  Node *current = head;
  size_t i = 0;
  while (i < s.size()) {
    if (current->data[ctoi(s[i])] == nullptr)
      return false;
    current = current->data[ctoi(s[i])];
    i++;
  }
  return current->isEndOfWord;
}

bool trie::is_prefix(const string &s) {
  Node *current = head;
  size_t i = 0;
  while (i < s.size()) {
    if (current->data[ctoi(s[i])] == nullptr)
      return false;
    current = current->data[ctoi(s[i])];
    i++;
  }
  return true;
}

void trie::extender(Node *current, vector<string> &suffixes, string s = "") {
  for (size_t i = 0; i < 26; i++) {
    if (current->data[i] != nullptr) {
      if (current->data[i]->isEndOfWord)
        suffixes.push_back(s + itoc(i));
      extender(current->data[i], suffixes, s + itoc(i));
    }
  }
}

void trie::extend(const string &prefix, vector<string> &result) {
  Node *current = head;
  size_t i = 0;
  while (i < prefix.size()) {
    if (current->data[ctoi(prefix[i])] == nullptr)
      return;
    current = current->data[ctoi(prefix[i])];
    i++;
  }
  if (current->isEndOfWord)
    result.push_back(prefix);
  vector<string> suffixes;
  extender(current, suffixes);
  for (auto s : suffixes) {
    result.push_back(prefix + s);
  }
}

void trie::print() {}