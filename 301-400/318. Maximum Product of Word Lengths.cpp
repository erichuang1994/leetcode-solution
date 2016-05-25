#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProduct(vector<string> &words) {
    if (words.size() <= 1) {
      return 0;
    }
    unordered_map<int, int> m;
    int base[26];
    for (int i = 0, temp = 1; i < 26; i++, temp = temp << 1) {
      base[i] = temp;
    }
    for (auto word : words) {
      int key = 0;
      for (int i = 0; i < word.length(); i++) {
        key = key | base[word[i] - 'a'];
      }
      // cout << "word = " << word << " key=" << key << endl;
      if (m.find(key) != m.end()) {
        m[key] = m[key] > word.length() ? m[key] : word.length();
      } else {
        m[key] = word.length();
      }
    }
    int ret = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      for (auto temp = it; temp != m.end(); temp++) {
        if ((it->first & temp->first) == 0) {
          ret =
              it->second * temp->second > ret ? it->second * temp->second : ret;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution a;
  vector<string> v;
  string b[] = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  for (auto i : b) {
    v.push_back(i);
  }
  cout << a.maxProduct(v) << endl;
  return 0;
}
