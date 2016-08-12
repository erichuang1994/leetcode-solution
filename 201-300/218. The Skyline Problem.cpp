class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    vector<int> vec;
    map<int, int> m;
    vector<pair<int, int>> ret;
    if (buildings.empty()) {
      return ret;
    }
    for (auto &building : buildings) {
      vec.push_back(building[0]);
      vec.push_back(building[1]);
    }
    sort(vec.begin(), vec.end());
    // for (auto x : vec) {
    //   cout << x << " ";
    // }
    // cout << endl;
    // int num = 0;
    // for (auto it = vec.begin(); it != vec.end();) {
    //   num++;
    //   if (*it == *(it + 1)) {
    //     cout << *it << endl;
    //     it = vec.erase(it);
    //   } else {
    //     it++;
    //   }
    // }
    // cout << num << endl;
    // cout << vec.size() << endl;
    auto last = std::unique(vec.begin(), vec.end());
    // v now holds {1 2 3 4 5 6 7 x x x x x x}, where 'x' is indeterminate
    vec.erase(last, vec.end());
    int len = vec.size();
    for (int i = 0; i < len; i++) {
      m[vec[i]] = i;
    }
    vector<int> h(vec.size(), 0);
    for (auto &building : buildings) {
      int i = m[building[0]];
      h[i] = max(h[i], building[2]);
      for (; vec[i] < building[1]; i++) {
        h[i] = max(h[i], building[2]);
      }
    }
    for (int i = len - 1; i > 0; i--) {
      if (h[i] != h[i - 1]) {
        ret.push_back(make_pair(vec[i], h[i]));
      }
    }
    ret.push_back(make_pair(vec[0], h[0]));
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
