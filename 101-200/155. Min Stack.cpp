// #include <climits>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  stack<int> s;
  stack<int> min;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (min.empty()) {
      min.push(x);
    } else if (min.top() >= x) {
      min.push(x);
    }
    s.push(x);
  }

  void pop() {
    if (s.top() == min.top()) {
      min.pop();
    }
    s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main() {
  cout << (INT_MAX) << endl;
  // printf("%d\n", INT_MAX);
  // cout << "asd" << endl;
  return 0;
}
