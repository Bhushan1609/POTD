class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>dp(nums.size(),1);
        vector<int>indexing(nums.size(),-1);
        int maxiLen=1,lastChosenIndex=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        indexing[i]=j;
                    }

                    if(dp[i]>maxiLen){
                        maxiLen=dp[i];
                        lastChosenIndex=i;
                    }
                }
            }
        }
        vector<int>answer;
        while(lastChosenIndex != -1){
            answer.push_back(nums[lastChosenIndex]);
            lastChosenIndex=indexing[lastChosenIndex];
        }
        return answer;
    }
};