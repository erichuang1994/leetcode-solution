class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    vector<pair<int, int>> vec;
    if(nums.empty())return false;
    int min, max;
    min = max = nums[0];
    vec.emplace_back(min, max);
    for (int i = 1; i < nums.size(); ++i) {
      if(nums[i]<vec.back().second&&nums[i]>vec.back().first)return true;
      if (nums[i] < min) {
        auto top = vec.back();
        if (max < top.second) {
          vec.emplace_back(min, max);
        }
        min = max = nums[i];
      } else if (nums[i] > max) {
        max = nums[i];
        if (max > vec.back().second) {
          vec.back().second = max;
          vec.back().first = min;
          while (vec.size() > 1 &&
                 vec[vec.size() - 2].second < vec.back().second) {
            vec[vec.size() - 2].second = vec.back().second;
            vec[vec.size() - 2].first = vec.back().first;
            vec.pop_back();
          }
          if(vec.size()>1&&vec[vec.size() - 2].first < vec.back().second)return true;
        }
      } else if (nums[i] > min && nums[i] < max) {
        return true;
      }
    }
    return false;
  }
};
