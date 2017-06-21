#include <map>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s)
            switch(c){
                case '(':
                    st.push(')');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '{':
                    st.push('}');
                    break;
                default:
                    if(st.empty()|| st.top()!=c)
                        return false;
                    st.pop();
            }
        return st.empty();
    }
};