class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int ret = 0;
		sort(nums.begin(), nums.end());
		for (auto i = nums.size() - 1; i > 1; --i) {
			int k  = 0;
			int j = i - 1;
			while (j > 0 && k < j) {
				if (nums[k] + nums[j] > nums[i]) {
					ret += j - k;
					--j;
				} else {
					++k;
				}
			}
		}
		return ret;
	}
};