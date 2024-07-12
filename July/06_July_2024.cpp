class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=time/(n-1);
        int rem=time%(n-1);
        if(dir%2==0){
            return rem+1;
        }
        else{
            return n-rem;
        }
    }
};

class Solution {
    public int passThePillow(int n, int time) {
        int dir=time/(n-1);
        int rem=time%(n-1);
        if(dir%2==0){
            return rem+1;
        }
        else{
            return n-rem;
        }
    }
}

/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function(n, time) {
    let dir=parseInt(time/(n-1));
    let rem=parseInt(time%(n-1));
    if(dir%2==0){
        return rem+1;
    }
    else{
        return n-rem;
    }
};