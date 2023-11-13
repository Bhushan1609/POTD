//1458
class Solution {
public:
    int dpArray[501][501]; // declaring dpArray
    int dpfunction(int i , int j , int& n , int& m , vector <int>& nums1 , vector<int>& nums2){
        if(i >= n or j >= m){ // if the any index from two array's may bound return most -ve value
            return -1e9;
        }
        if(dpArray[i][j] != -1) return dpArray[i][j];
        int prod  = nums1[i] * nums2[j] ; // taking product from alternate array
        int takeBoth = (nums1[i] * nums2[j]) + dpfunction(i+1 , j+1 , n , m , nums1 , nums2);
        // take both and pass recursion for next indexes
        int takeI = dpfunction(i+1 , j  , n , m ,nums1 , nums2); //increase i and constant j
        int takeJ = dpfunction(i , j+1  , n , m ,nums1 , nums2); //increase j and constant i
        return dpArray[i][j] = max({prod , takeBoth , takeI , takeJ}); // returning max value among them
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i ,j;
        i = j = 0;
        memset(dpArray , -1 , sizeof(dpArray));
        return dpfunction(i , j , n , m , nums1 , nums2);
    }
};
