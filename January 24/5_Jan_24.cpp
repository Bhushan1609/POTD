// 300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>answer;
        for(auto i:nums){
            if(answer.empty()){
                answer.push_back(i);
                continue;
            }
            int index=lower_bound(answer.begin(),answer.end(),i)-answer.begin();
            if(index==answer.size()){
                answer.push_back(i);
            }
            else if(answer[index]!=i)answer[index]=i;
        }
        return answer.size();
    }
};