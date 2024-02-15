//931. Minimum Falling Path Sum
class Solution {
public:
    int recursion(int i,int j,vector<vector<int>>& matrix,int n,int m,vector<vector<int>>&dp){
        if(i==(n-1)) return matrix[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int minPath=INT_MAX;
        vector<int>arr1={+1,+1,+1},arr2={-1,0,+1};
        for(int it=0;it<3;it++){
            int newi=i+arr1[it];
            int newj=j+arr2[it];
            if(newi>=0 and newi<n and newj>=0 and newj<m){
                int ans=matrix[i][j]+recursion(newi,newj,matrix,n,m,dp);
                minPath=min(ans,minPath); 
            }
        }
        return dp[i][j]=minPath;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int minPath=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        for(int j=0;j<m;j++){
            int ans=recursion(0,j,matrix,n,m,dp);
            minPath=min(ans,minPath); 
        }
        return minPath;
    }
};