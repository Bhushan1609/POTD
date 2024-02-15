class Solution {
public:
    int dp[1001][1001];
    int recursion(int i,int j,string s){
        if(i==j or i>j)return 1;
        if(s[i]!=s[j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=recursion(i+1,j-1,s);
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans = ans + recursion(i,j,s);
            }
        }
        return ans;
    }
};