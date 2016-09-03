class Solution {
public:
  bool isMatch(string s, string p) {
    int lens = s.length();
    int lenp = p.length();
    // code commented below can make it faster under the leetcode testcase
    // int count = 0;
    // for (int i = 0; i < lenp; i++)
    //   if (p[i] == '*')
    //     count++;
    // if ((count == 0 && lens != lenp) || (lenp - count > lens))
    //   return false;
    if (p.empty() && !s.empty()) {
      return false;
    }
    if (s.empty()) {
      for (int i = 0; i < lenp; i++) {
        if (p[i] != '*') {
          return false;
        }
      }
      return true;
    }
    int num = 0;
    // dp[0] for empty
    int dp[lens + 1];
    if (p[0] == '*') {
      fill_n(dp, lens + 1, 1);
    } else {
      fill_n(dp, lens + 1, 0);
      dp[1] = p[0] == '?' || s[0] == p[0] ? 1 : 0;
      num++;
    }
    for (int i = 1; i < lenp; i++) {
      if (p[i] == '*') {
        bool flag = dp[num];
        for (int j = num; j <= lens; j++) {
          flag = flag | dp[j];
          dp[j] = flag;
        }
      } else {
        if (num >= lens) {
          return false;
        }
        for (int j = lens; j > num; j--) {
          dp[j] = dp[j - 1] == 1 && (p[i] == '?' || p[i] == s[j - 1]) ? 1 : 0;
        }
        dp[0] = 0;
        num++;
      }
    }
    return dp[lens];
  }
};
// 下面的方法只回溯最近一次*出现的地方(此处需要理解一下)
// class Solution {
// public:
//     bool isMatch(const char *s, const char *p) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//
//         const char* star=NULL;
//         const char* ss=s;
//         while (*s){
//             if ((*p=='?')||(*p==*s)){s++;p++;continue;}
//             if (*p=='*'){star=p++; ss=s;continue;}
//             if (star){ p = star+1; s=++ss;continue;}
//             return false;
//         }
//         while (*p=='*'){p++;}
//         return !*p;
//     }
// };
