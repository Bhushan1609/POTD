//343
int dpArray[59];
class Solution {
public:
    int calldp( int n ){
        if(n <= 1) {
            return 1;
        }
        if(dpArray[n] != -1){
            return dpArray[n];
        } 
        int result = INT_MIN;
        for (int i = 1 ; i < n ; i++){
            int prod = i * max(n - i , calldp(n-i)); 
            result = max(result , prod);
        }
        return dpArray[n] = result;
    }
    int integerBreak(int n) {
        for (int i = 0 ; i < 59 ; i++) dpArray[i] = -1;
        return calldp(n);        
    }
};
