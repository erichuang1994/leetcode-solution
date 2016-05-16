#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
// 对于每一位上1出现的次数都可以用一个编码来表示，
// 比如对于一位的情况，00,01,10,11可以分别表示出现了0次，1次，2次，3次。
// 类似的对于本题，把状态表示成循环码00,01,10,00
// 如果我们能用两位的码表示每一位的当前状态，那么对于出现三次的数，
// 其状态码为00，对于出现一次的数其状态码为01.
// 所以可以用两个int将其保存下来。
// 第一个整数存所有的第一位，第二个整数存所有的第二位。
// 这个思路还可以解决类似的一些问题，值得继续挖掘（有空
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int odd = 0;
    int even = 0;
    for (auto &num : nums) {
      odd = (odd ^ num) & (~even);
      even = (even ^ num) & (~odd);
    }
    return odd;
  }
};
using namespace std;
int main() {}
