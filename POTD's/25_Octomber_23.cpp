//779
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n ==1 and k ==1 ) return 0;
        int size = pow(2 , n - 1);
        int mid = size / 2;
        if(k <= mid) return kthGrammar(n-1 , k);
        return 1 - kthGrammar(n-1 ,k-mid);
    }
};
