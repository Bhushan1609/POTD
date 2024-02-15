class Solution {
public:
    int dp[10001];
    int recursion(int n){
        if(n<0) return 1e9;
        if(n==0) return 0;
        if(dp[n]!=-1)return dp[n];
        int ans=1e9;
        for(int i=1;i<=n;i++){
            int prod=i*i;
            int rec=1+recursion(n-prod);
            ans=min(ans,rec);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return recursion(n);
    }
};