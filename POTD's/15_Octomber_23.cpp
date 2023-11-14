//1269
class Solution {
public:
    int mod = 1e9 + 7;
    int dpArray[501][501];
    int dpfunction(int index , int steps , int n){
        if(index < 0 or index >= n) return 0;
        if(steps == 0){
            return index == 0;
        }
        if(dpArray[index][steps] != -1) 
            return dpArray[index][steps];

        int goleft = (dpfunction(index-1 , steps-1 , n)) % mod ;// goleft
        goleft = ( goleft + dpfunction(index , steps-1 , n)) % mod ;//stay
        goleft = (goleft + dpfunction(index+1 , steps-1 , n)) % mod;//goright
        return dpArray[index][steps] = (goleft % mod) ;
    }
    int numWays(int steps, int arrLen) {
        int index = 0;
        int n = arrLen;
        memset(dpArray , -1 , sizeof(dpArray));
        return dpfunction(index , steps , n);
    }
};
