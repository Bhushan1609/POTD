// 557
class Solution {
public:
    string reverseWords(string s) {
        stack <char> st;
        string ret = "";
        for (auto i : s){
            int ans = i;akdsd
            if(ans == 32){
                while(!st.empty()){
                    char ch = st.top();
                    ret.push_back(ch);
                    st.pop();
                }
                ret.push_back(' ');
            }
            else st.push(i);
        }
        while(!st.empty()){
            char ch = st.top();
            ret.push_back(ch);
            st.pop();
        }
        return ret;
    }
};
