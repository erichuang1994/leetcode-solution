class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> flag(26, 0);
    vector<int> ret;
    if (s.size() < p.size()) {
      return ret;
    }
    int count = p.size();
    for (int i = 0; i < count; ++i) {
      flag[p[i] - 'a']++;
    }
    for (int i = 0; i < count; ++i) {
      flag[s[i] - 'a']--;
    }
    for (int i = 0; i <= s.size() - p.size(); ++i) {
      bool f = true;
      for (int j = 0; j < 26; ++j) {
        if (flag[j]) {
          f = false;
          break;
        }
      }
      if (f) {
        ret.push_back(i);
      }
      flag[s[i] - 'a']++;
      if (i + p.size() < s.size())
        flag[s[i + p.size()] - 'a']--;
    }
    return ret;
  }
};
