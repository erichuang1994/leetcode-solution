#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    dfs(ret, "", s, 0);
    // for(int i = 0;i<ret.size();i++){
    // 	// cout<<"here"<<endl;
    // 	cout<<ret[i]<<endl;
    // }
    return ret;
  }
  // // 找到比cur大的下一个组合数
  // vector<int> next_combination(vector<int> &cur,vector<int> &left){

  // }
  // void dfs(vector<string> &ret,int cur,vector<int> &cur,string &s){
  // 	if(cur.size() == 3){
  // 		int begin = 0;
  // 		for(int i = 0;i<3;i++){
  // 			if(string.substr(begin,))
  // 		}
  // 	}
  // }
  bool check(string s){
  	if(s.length()>1 and s[0] == '0'){
  			return false;
  	}else{
  		// cout<<s<<endl;

  		int temp = 0;
  		int lens = s.length();
  		for(int i = 0;i<lens;i++){
  			temp = temp*10 + (s[i]-'0');
  		}
  		// cout<<s<<endl;
  		return temp<=255;
  	}
  }
  void dfs(vector<string> &ret,string s,string l,int count){
  	if(count == 4){
  		if(l.size()!=0){
  			return;
  		}
		// ret.push_back(s.erase(0,1));
		ret.push_back(s.substr(1));
		return;
  	}
  	int lena = l.size()<3?l.size():3;
  	if(l.size()>(4-count)*3) return;
  	if(l.size()<(4-count)) return;
  	int num = 0 ;
  	for(int i = 0;i<lena;i++){
  		num = num*10 + (l[i]-'0');
  		if(num<=255){
  			dfs(ret,s+"."+l.substr(0,i+1),l.substr(i+1),count+1);
  		}
  		if(num == 0) break;
  	}
  }
};

int main(){
	Solution a;
	string s("010010");
	// cout<<s.substr(0,1)<<endl;;
	a.restoreIpAddresses(s);
}