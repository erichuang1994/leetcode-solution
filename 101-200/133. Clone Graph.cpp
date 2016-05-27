#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x){};
};
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL)
      return NULL;
    unordered_map<int, UndirectedGraphNode *> s;
    return dfs(s, node);
  }
  UndirectedGraphNode *dfs(unordered_map<int, UndirectedGraphNode *> &s,
                           UndirectedGraphNode *node) {
    if (s.find(node->label) != s.end()) {
      return s.find(node->label)->second;
    }
    UndirectedGraphNode *temp = new UndirectedGraphNode(node->label);
    s[node->label] = temp;
    for (auto neighbor : node->neighbors) {
      temp->neighbors.push_back(dfs(s, neighbor));
    }
    return temp;
  }
};

int main() {
  // Solution a;
  // int v = {};
  return 0;
}
