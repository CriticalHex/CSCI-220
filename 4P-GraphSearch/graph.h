#ifndef _GRAPH_BFS_H
#define _GRAPH_BFS_H

#include <vector>

using namespace std;

class graph {
public:
  graph(int vertex_count);
  ~graph();
  void add_edge(int from, int to);
  vector<int> find_shortest_path(int from, int to);

private:
  struct node {
    vector<size_t> edges;
    bool isVisited = false;
    size_t prev = -1;
    size_t i;
  };
  vector<node *> nodes;
};

#endif
