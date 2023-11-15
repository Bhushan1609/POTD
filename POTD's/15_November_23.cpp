//1846
class Solution {
public:
    int callbrute(vector <int>& arr){
        if(arr.size() == 1) return 1;
        bool flag = false;
        sort(arr.begin() , arr.end()); // nlog(n)
        arr[0] = 1;
        for (int i = 1 ; i < arr.size()  ; i++){ // O(n)
            if(abs(arr[i] - arr[i-1]) > 1){
                arr[i] = (arr[i-1] + 1);
            }
        }
        return arr[arr.size() -1];
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        return callbrute(arr);
    }
};
