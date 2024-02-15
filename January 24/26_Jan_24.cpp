// 576. Out of Boundary Paths
class Solution {
public:
    const int mod=1e9+7;
    int dp[51][51][51];
    bool boundary(int x,int y,int m ,int n){
        if(y==-1){
            if(x>=0 and x<m) return 1;
        }
        if(x==-1){ 
            if(y>=0 and y<n) return 1;
        }
        if(x==m){
            if(y>=0 and y<n) return 1;
        }
        if(y==n){
            if(x>=0 and x<m) return 1;
        }
        return 0;
    }
    int recursion(int x,int y,int m,int n,int moves){
        if(moves<0) return 0;
        if (x<0 || x==m || y<0 || y==n) return 1;
        if(dp[x][y][moves]!=-1)return dp[x][y][moves];
        vector<int>arr1={-1,0,0,+1},arr2={0,-1,+1,0};     
        int ans=0;
        for(int it=0;it<4;it++){
            int newx=x+arr1[it];
            int newy=y+arr2[it];
            if(newx>=-1 and newx<=m and newy>=-1 and newy<=n){
                ans=(ans+recursion(newx,newy,m,n,moves-1))%mod;
            }
        }
        return dp[x][y][moves]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return recursion(startRow,startColumn,m,n,maxMove);
    }
};