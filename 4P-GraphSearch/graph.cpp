#include "graph.h"
#include <algorithm>
#include <queue>

using namespace std;

graph::graph(int vertex_count) {
  nodes.resize(vertex_count);
  for (size_t i = 0; i < (size_t)vertex_count; i++) {
    node *n = new node;
    n->i = i;
    nodes.at(i) = n;
  }
}

graph::~graph() {
  for (size_t i = 0; i < nodes.size(); i++) {
    delete nodes.at(i);
  }
  nodes.clear();
}

void graph::add_edge(int from, int to) { nodes.at(from)->edges.push_back(to); }

vector<int> graph::find_shortest_path(int from, int to) {
  vector<node *> visited;
  vector<int> path;
  queue<node *> q;
  node *n = nodes.at(from);
  q.push(n);
  visited.push_back(n);
  n->isVisited = true;
  bool found = false;
  while (!q.empty() && !found) {
    for (size_t i : q.front()->edges) {
      n = nodes.at(i);
      if (!n->isVisited) {
        n->prev = q.front()->i;
        visited.push_back(n);
        n->isVisited = true;
        if (i == (size_t)to)
          found = true;
        else
          q.push(n);
      }
    }
    q.pop();
  }
  if (found) {
    n = nodes.at(to);
    while (true) {
      path.push_back(n->i);
      if (n->prev == (size_t)-1)
        break;
      n = nodes.at(n->prev);
    }
    reverse(path.begin(), path.end());
  }
  for (auto n : visited) {
    n->prev = -1;
    n->isVisited = false;
  }
  return path;
}
