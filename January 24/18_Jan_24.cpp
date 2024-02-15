//70. Climbing Stairs
class Solution {
public:
    int recursion(int i,int n,vector<int>&dp){
        if(i>=n){
            if(i==n) return 1;
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int one=recursion(i+1,n,dp);
        int two=recursion(i+2,n,dp);
        return dp[i]=one+two;
    }
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        return recursion(0,n,dp);
    }
};