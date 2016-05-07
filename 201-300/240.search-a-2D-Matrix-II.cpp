// 上下排序，左右排序的matrix寻找target.
// 下面是自己想的naive的二分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
  		int m = matrix.size();
  		int n = matrix[0].size();
  		int hi = n;
  		for(int i = 0;i<m;i++){
  			int lo = 0;
  			int mid;
  			while(lo<hi){
  				mid = (lo+hi)/2;
  				if(matrix[i][mid] == target){
  					return true;
  				}else if(matrix[i][mid] > target){
  					hi = mid;
  				}else{
  					lo = mid+1;
  				}
  			}
  		}
  		return false;
    }
};

// discuss中的最优答案 复杂度0(m+n)
// 代码也比二分容易很多。。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int i = 0,j = n-1;
      while(i<m && j>=0){
        if(matrix[i][j] == target){
          return true;
        }else if(matrix[i][j]>target){
          j--;
        }else{
          i++;
        }
      }
      return false;
    }
};