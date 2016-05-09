#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double m = x;
        // double delta = 0.0001;
        if(x == 1 || x == 0){
        	return x;
        }
        while(abs(m*m - x)>=1){
        	m = (m+x/m)/2;
        }
        return m;
    }
};

int main(){
	int v[] = {1,2,3,4,256};
	Solution a;
	for(int i = 0;i<5;i++){
		cout<<a.mySqrt(v[i])<<endl;
	}
}