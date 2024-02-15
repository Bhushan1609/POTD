class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector <vector <int>> answer;
        vector <int> count(201 , 0);
        int maxi = 0;
        for (auto i : nums) {
            count[i]++;
            maxi = max(maxi , count[i]);
        }
        while(maxi--){
            vector <int> dummy;
            for (int i = 1 ; i < 201 ; i++){
                if(count[i]){
                    count[i] -= 1;
                    dummy.push_back(i);
                }
            }
            answer.push_back(dummy);
        }
        return answer;
    }
};