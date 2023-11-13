//1420
class Solution {
public:
    int mod = 1e9 + 7;
    int dpArray[51][51][101];
    int dpfunction(int index , int searchCost , int maxi , int k , int n , int m){
        if(index >= n){
            // searching is equals to k then return 1
            if(searchCost == k) return 1;
            return 0;
        }
        if(dpArray[index][searchCost][maxi] != -1) 
            return dpArray[index][searchCost][maxi];
        int result = 0;
        // putting all indexes from 1 to m
        for (int i = 1 ; i <= m ; i++){
            // checking i is the greater than maxi , then upadate and increase searchCost
            // and also increase index++
            if(i > maxi){
                result = (result + dpfunction(index+1 , searchCost + 1 , i , k , n , m)) % mod;
            }
            else{
                result = (result + dpfunction(index+1 , searchCost  , maxi , k , n , m)) % mod;
            }
        }
        return dpArray[index][searchCost][maxi] = (result % mod);
    }
    int numOfArrays(int n, int m, int k) {
        int index = 0 , searchCost = 0, maxi = 0;
        memset( dpArray ,-1, sizeof(dpArray));
        return dpfunction(index , searchCost , maxi, k , n , m); 
    }
};
