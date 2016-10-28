class Solution {
public:
  bool dfs(int cur, vector<pair<int, int>> &events, vector<vector<int>> &edges,
           int &time) {
    if (events[cur].first != -1)
      return events[cur].second != -1;
    events[cur].first = time;
    for (auto &v : edges[cur])
      if (!dfs(v, events, edges, ++time))
        return false;
    events[cur].second = ++time;
    return true;
  }
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<pair<int, int>> events(numCourses, {-1, -1});
    vector<vector<int>> edges(numCourses);
    for (auto &pair : prerequisites) {
      edges[pair.first].push_back(pair.second);
    }
    int time = 0;
    for (int i = 0; i < events.size(); ++i) {
      if (!dfs(i, events, edges, time))
        return false;
    }
    return true;
  }
};
