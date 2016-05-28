#include <algorithm>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int hIndex(vector<int> &citations) {
    vector<int> m(citations.size() + 1, 0);
    int l = citations.size();
    for (int i = 0; i < l; i++) {
      if (citations[i] > l) {
        m[l]++;
      } else {
        m[citations[i]]++;
      }
    }
    if (m[l] == l) {
      return l;
    }
    for (int i = l - 1; i >= 0; i--) {
      m[i] += m[i + 1];
      if (m[i] >= i) {
        return i;
      }
    }
    return 0;
  }
};

int main() {
  Solution a;
  int v[] = {1, 3, 2, 4};
  vector<int> in(v, v + sizeof(v) / sizeof(v[0]));
  a.hIndex(in);
  return 0;
}
