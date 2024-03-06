#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to determine the indices that will not be visited in 100 probes
vector<int> unvisitedIndices(int hashTableSize, int startingIndex) {
  vector<int> unvisited;

  // Initialize a boolean array to keep track of visited indices
  vector<bool> visited(hashTableSize, false);

  int probeIndex;
  // Perform 100 probes
  for (int i = 0; i < 100; ++i) {
    int actualCount = 0;
    probeIndex = (startingIndex + (actualCount * actualCount)) % hashTableSize;
    while (visited[probeIndex] && std::all_of(visited.begin(), visited.end(),
                                              [](bool b) { return b; })) {
      probeIndex =
          (startingIndex + (actualCount * actualCount)) % hashTableSize;
      actualCount++;
    }
    visited[probeIndex] = true;
    for (bool t : visited) {
      cout << t << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Check which indices were not visited
  for (int i = 0; i < hashTableSize; ++i) {
    if (!visited[i]) {
      unvisited.push_back(i);
    }
  }

  return unvisited;
}

int main() {
  int hashTableSize, startingIndex;
  vector<int> unvisited;
  for (hashTableSize = 20 - 1; hashTableSize >= 0; hashTableSize--) {
    for (startingIndex = 0; startingIndex < hashTableSize; startingIndex++) {
      unvisited = unvisitedIndices(hashTableSize, startingIndex);
      if (unvisited.empty()) {
        cout << "All indices will be visited in 100 probes." << endl;
      }
    }
  }

  return 0;
}
