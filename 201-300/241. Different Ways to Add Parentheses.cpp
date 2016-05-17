#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// 和95. Unique Binary Search Trees II思想是一样的。
// 这回我直接递归了，有许多冗余
// 使用自低向上的DP可以加快速度。
// 不过既然已经过了。。
class Solution {
private:
  struct Node {
    int value;
    char op;
    bool isValue;
    Node(int value, bool isValue, char op) {
      this->value = value;
      this->isValue = isValue;
      this->op = op;
    }
  };

public:
  bool checkop(char op) { return (op == '+' || op == '-' || op == '*'); }
  vector<int> diffWaysToCompute(string input) {
    vector<int> ret;
    if (input == "") {
      return ret;
    }
    vector<Node> nodes;
    int last = 0;
    for (int i = 0; i < input.size(); i++) {
      if (checkop(input[i])) {
        nodes.push_back(
            Node(atoi(input.substr(last, i - last).c_str()), true, '.'));
        nodes.push_back(Node(1, false, input[i]));
        last = i + 1;
      }
    }
    nodes.push_back(Node(atoi(input.substr(last).c_str()), true, '.'));
    return cal(nodes, 0, nodes.size() - 1);
  }
  vector<int> cal(vector<Node> &nodes, int begin, int end) {
    vector<int> ret;
    if (begin == end) {
      ret.push_back(nodes[begin].value);
      return ret;
    }
    for (int i = begin + 1; i < end; i += 2) {
      vector<int> lefts = cal(nodes, begin, i - 1);
      vector<int> rights = cal(nodes, i + 1, end);
      for (auto &l : lefts) {
        for (auto &r : rights) {
          switch (nodes[i].op) {
          case '+':
            ret.push_back(l + r);
            break;
          case '-':
            ret.push_back(l - r);
            break;
          case '*':
            ret.push_back(l * r);
            break;
          }
        }
      }
    }
    return ret;
  }
};

int main() {
  // Solution a;
  // string
  return 0;
}
