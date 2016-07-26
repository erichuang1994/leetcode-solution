class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l,r1,r2;
        r1 = nums.size()-1;
        r2 = nums.size()-2;
        l = 0;
        vector<vector<int>> ret;
        for(int x = nums.size()-1;x>=0;x--){
            int z=0;
            for(auto y = x-1;y>z;y--){
                z = lower_bound(nums.begin()+z,nums.begin()+y,-(nums[x]+nums[y]))-nums.begin();
                if(y!=z&&nums[z]+nums[x]+nums[y]==0){
                    ret.push_back(vector<int>({nums[x],nums[y],nums[z]}));
                }
                while(y>1&&nums[y]==nums[y-1]){
                    y--;
                }
            }
            while(x>1&&nums[x]==nums[x-1]){
                x--;
            }
        }
        return ret;
    }
};