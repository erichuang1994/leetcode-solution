#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// seems better
// class Solution {
// public:
//     static string numberToWords(int n) {
//         if(n == 0) return "Zero";
//         else return int_string(n).substr(1);
//     }
// private:
//     static const char * const below_20[];
//     static const char * const below_100[];
//     static string int_string(int n) {
//         if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion"
//         + int_string(n - 1000000000 * (n / 1000000000));
//         else if(n >= 1000000) return int_string(n / 1000000) + " Million" +
//         int_string(n - 1000000 * (n / 1000000));
//         else if(n >= 1000)    return int_string(n / 1000) + " Thousand" +
//         int_string(n - 1000 * (n / 1000));
//         else if(n >= 100)     return int_string(n / 100) + " Hundred" +
//         int_string(n - 100 * (n / 100));
//         else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] +
//         int_string(n - 10 * (n / 10));
//         else if(n >= 1)       return string(" ") + below_20[n - 1];
//         else return "";
//         }
//     }
// };
//
// const char * const Solution::below_20[] =  {"One", "Two", "Three",
// "Four","Five","Six","Seven","Eight","Nine","Ten",
// "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
// const char * const Solution::below_100[] = {"Twenty", "Thirty", "Forty",
// "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
  string numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }
    int nums[] = {1, 1000, 1000000, 1000000000};
    string units[] = {"", "Thousand", "Million", "Billion"};
    string digits[] = {"Zero", "One", "Two",   "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine"};
    string undertwenty[] = {"Eleven",   "Twelve",  "Thirteen",  "Fourteen",
                            "Fifteen",  "Sixteen", "Seventeen", "Eighteen",
                            "Nineteen", "Twenty"};
    string ties[] = {"Ten",   "Twenty",  "Thirty", "Forty", "Fifty",
                     "Sixty", "Seventy", "Eighty", "Ninety"};

    string ret = "";
    int len = getIntLen(num);
    int tmp, hundreds, tensdigit, singledigits;
    for (int i = len / 3; i >= 0; i--) {
      tmp = (num / nums[i]) % 1000;
      hundreds = tmp / 100;
      tensdigit = (tmp / 10) % 10;
      singledigits = tmp % 10;
      if (tmp == 0) {
        continue;
      }
      int dozens = tmp % 100;
      if (hundreds > 0) {
        ret += digits[hundreds] + " Hundred ";
      }
      if (10 < dozens && dozens < 20) {
        ret += undertwenty[dozens - 11] + " ";
      } else {
        if (tensdigit > 0) {
          ret += ties[tensdigit - 1] + " ";
        }
        if (singledigits > 0) {
          ret += digits[singledigits] + " ";
        }
      }
      ret += units[i] + " ";
    }
    len = ret.length();
    while (isspace(ret[len - 1])) {
      len--;
    }
    return ret.substr(0, len);
  }
  int getIntLen(int num) {
    long base = 10;
    int len = 1;
    while (base <= num) {
      base *= 10;
      len++;
    }
    return len;
  }
};

int main() {
  cout << INT32_MAX << endl;
  cout << sizeof(int) << endl;
  Solution a;
  cout << a.numberToWords(1600000000) << endl;
  return 0;
}
