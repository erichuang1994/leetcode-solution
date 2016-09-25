#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    auto com = [](const pair<int, int> a, const pair<int, int> b) {
      return a.first != b.first ? a.first > b.first : a.second < b.second;
    };
    sort(people.begin(), people.end(), com);
    vector<pair<int, int>> ret;
    int len = people.size();
    for (int i = 0; i < len; i++) {
      if (people[i].second == ret.size()) {
        ret.emplace_back(people[i].first, people[i].second);
      } else {
        ret.emplace(ret.begin() + people[i].second, people[i].first,
                    people[i].second);
      }
    }
    return ret;
  }
};
// int main() {
//   Solution a;
//   vector<pair<int, int>> vec = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5,
//   2}};
//   a.reconstructQueue(vec);
// }
