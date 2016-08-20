class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    multimap<int, int> coords;
    for (auto &building : buildings) {
      coords.emplace(building[0], building[2]);
      coords.emplace(building[1], -building[2]);
    }
    multiset<int> heights = {0};
    map<int, int> res;
    for (auto &p : coords) {
      if (p.second > 0) {
        heights.insert(p.second);
      } else {
        heights.erase(heights.find(-p.second));
      }
      res[p.first] = *heights.rbegin();
    }
    auto com = [](pair<int, int> l, pair<int, int> r) {
      return l.second == r.second;
    };
    vector<pair<int, int>> results;
    unique_copy(res.begin(), res.end(),
                back_insert_iterator<vector<pair<int, int>>>(results), com);
    return results;
  }
};
