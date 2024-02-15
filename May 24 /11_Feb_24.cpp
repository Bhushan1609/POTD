class Solution {
public:
    int dp[71][71][71];
    int recursion(int i,int j1,int j2,vector<vector<int>>&grid,int n,int m){
        if(i==n-1)return (j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=0;
        vector<int>robo1Move={-1,0,+1};
        for(int r1=0;r1<3;r1++){
            for(int r2=0;r2<3;r2++){
                int newj1=j1+robo1Move[r1];
                int newj2=j2+robo1Move[r2];
                if(newj1>=0 and newj1<m and newj2>=0 and newj2<m){
                    int addUp=(j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
                    addUp+=recursion(i+1,newj1,newj2,grid,n,m);
                    ans=max(ans,addUp);
                }
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return recursion(0,0,m-1,grid,n,m);
    }
};