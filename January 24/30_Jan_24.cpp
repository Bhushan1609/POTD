class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        unordered_map<string, function<int (int, int) > > mp = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        for(auto i:tokens){
            if(i == "+" or i == "-" or i == "*" or i == "/" ){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(mp[i](a,b));
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};