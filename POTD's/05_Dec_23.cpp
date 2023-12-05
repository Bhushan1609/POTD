//1688
class Solution {
public:
    int callbrute(int n){ // O(log(n))
        int ans = 0;
        while(1){
            if(n == 1) return ans;
            if(n&1){
                ans += (n-1)/2;
                n = (n-1)/2 + 1;
            }
            else{
                ans += (n/2);
                n = n/2;
            }
        }
        return ans;
    }
    int calloptimal(int n) {return n-1;} // O(1)
    int numberOfMatches(int n) {
        // return callbrute(n);
        return calloptimal(n);
    }
};
