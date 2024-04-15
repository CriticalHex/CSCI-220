#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

using namespace std;

class trie {

private:
  class Node {
  private:
  public:
    Node *data[26];
    bool isEndOfWord;
    Node();
    ~Node();
  };
  void extender(Node *current, vector<string> &suffixes, string s);

public:
  trie();
  ~trie();
  Node *head;
  void insert(const string &s);
  bool contains(const string &s);
  bool is_prefix(const string &s);
  void extend(const string &prefix, vector<string> &result);
  void print();
};

#endif
