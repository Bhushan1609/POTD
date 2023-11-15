// 5
// Learn manchers algo for linear time !!!!!!
// O(n^2)
class Solution {
public:
    string S;
    int dpArray[1001][1001];
    bool dpfunction(int i , int j){
        if(i >= j) return 1;
        if(dpArray[i][j] != -1){
            return dpArray[i][j];
        }
        if(S[i] == S[j]){
            return dpArray[i][j] = dpfunction(i+1 , j-1);
        }
        else{
            return dpArray[i][j] = 0;
        }
    }
    string longestPalindrome(string s) {
        S = s;
        int n = s.size() ;
        int start = 0;
        int maxi = INT_MIN;
        memset(dpArray , -1 , sizeof(dpArray));
        for (int i = 0 ; i < n ; i++){
            for (int j = i ; j < n ; j++){
                if(dpfunction(i , j)){
                    if(j - i + 1 > maxi){
                        start = i;
                        maxi = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start , maxi);
    }
};
