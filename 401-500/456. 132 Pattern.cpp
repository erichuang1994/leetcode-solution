class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    vector<pair<int, int>> vec;
    if(nums.empty())return false;
    int min, max;
    min = max = nums[0];
    vec.emplace_back(min, max);
    for (int i = 1; i < nums.size(); ++i) {
      if((nums[i]<vec.back().second&&nums[i]>vec.back().first)||(nums[i] > min && nums[i] < max))return true;
      if (nums[i] < min) {
        auto top = vec.back();
        if (max < top.second) {
          vec.emplace_back(min, max);
        }
        min = max = nums[i];
      } else if (nums[i] > max) {
        max = nums[i];
        if (max > vec.back().second) {
          while(!vec.empty()&&vec.back().second < max)
            vec.pop_back();
          vec.emplace_back(min, max);
          if(vec.size()>1&&vec[vec.size() - 2].first < vec.back().second)return true;
        }
      }
    }
    return false;
  }
};
// 代码更短的版本
// class Solution {
// public:
//   bool find132pattern(vector<int> &nums) {
//     stack<int> s;
//     int min = INT_MIN;
//     for(int i = nums.size()-1;i>=0;--i){
//       if(nums[i]<min)return true;
//       else {
//         while(!s.empty()&&s.top()<nums[i]){
//           min = s.top();
//           s.pop();
//         }
//         s.push(nums[i]);
//       }
//     }
//     return false;
//   }
// };
