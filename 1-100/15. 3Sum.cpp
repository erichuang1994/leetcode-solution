class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        int len=nums.size();
        for(int x= 0;x<len;x++){
            int y = x+1;
            int z = len-1;
            while(y<z){
                int tmp = nums[x]+nums[y]+nums[z];
                if(tmp<0){
                    y++;
                }else if(tmp == 0){
                    ret.push_back(vector<int>({nums[x],nums[y],nums[z]}));
                    while(y<len-1&&nums[y]==nums[y+1]){
                        y++;
                    }
                    y++;
                }else{
                    z--;
                }
            }
            while(x<len-1&&nums[x]==nums[x+1]){
                x++;
            }
        }
        return ret;
    }
};