// 342
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        bool ans = false;
        if((n&(n-1)) == 0 and (n-1) % 3 == 0) return ans = true;
        return ans;    
    }
};      
