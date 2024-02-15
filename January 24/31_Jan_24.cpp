class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                answer[i] = 0;
            } else if (temperatures[st.top()] <= temperatures[i]) {
                while (!st.empty() and
                       temperatures[st.top()] <= temperatures[i]) {
                    st.pop();
                }
                if (st.empty())
                    answer[i] = 0;
                else {
                    answer[i] = abs(st.top() - i);
                }
            } else {
                answer[i] = abs(i - st.top());
            }
            st.push(i);
        }
        return answer;
    }
};