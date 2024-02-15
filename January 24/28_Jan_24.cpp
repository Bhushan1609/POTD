class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        for(int startRow=0;startRow<n;startRow++){
            for(int startCol=1;startCol<m;startCol++){
                matrix[startRow][startCol]=matrix[startRow][startCol]+matrix[startRow][startCol-1];
            }
        }
        for(int startRow=0;startRow<n;startRow++){
            int prefSum=0;
            unordered_map<int,int>mapp;
            mapp[prefSum]++;
            for(int startCol=0;startCol<m;startCol++){
                prefSum+=matrix[startRow][startCol];
                int need=prefSum-target;
                if(mapp[need]!=0){
                    cnt+=(mapp[need]);
                }
                mapp[prefSum]++;
            }
        }
        for(int startCol=0;startCol<m;startCol++){
            int prefSum=0;
            unordered_map<int,int>mapp;
            mapp[prefSum]++;
            for(int startRow=0;startRow<n;startRow++){
                prefSum+=matrix[startRow][startCol];
                int need=prefSum-target;
                if(mapp[need]!=0){
                    cnt+=(mapp[need]);
                }
                mapp[prefSum]++;
            }
        }
        return cnt;
    }
};