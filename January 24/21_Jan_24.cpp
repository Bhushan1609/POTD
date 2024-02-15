// 198. House Robber
class Solution {
public:
    int recursion(int index,int n,vector<int>&nums,vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1)return dp[index];
        int pick=nums[index]+recursion(index+2,n,nums,dp);
        int npick=recursion(index+1,n,nums,dp);
        return dp[index]=max(pick,npick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return recursion(0,nums.size(),nums,dp);
    }
};