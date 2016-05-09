#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int plus = 1;
        for(int i = digits.size()-1;i>=0;i--){
        	// if(digits[i] == 9){
        	// 	digits[i] = 0;
        	// }else{
        	// 	digits[i]++;
        	// 	return digits;
        	// }
        	// digits[i]++;
        	digits[i] = (++digits[i])%10;
        	if(digits[i] != 0){
        		return digits;
        	}
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main(){
	int v[] = {9,9,9,9};
	vector<int> digits(v,v+sizeof(v)/sizeof(v[0]));
	Solution a;
	vector<int> ans = a.plusOne(digits);
	for(auto i : ans){
		cout<<i;
	}
	cout<<endl;
}