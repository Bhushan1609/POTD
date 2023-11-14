//1793
class Solution {
public:
    int callgreddy(vector <int>& nums , int k){
        int start = k;
        int end = k;
        int mini = nums[k];
        int ans = nums[k];
        while(start > 0 or end < nums.size()-1){
            int first = (start > 0) ? nums[start-1] : 0;
            int second = (end < nums.size() - 1) ? nums[end+1] : 0;
            if(first >= second){
                start = start - 1;
                mini = min(mini , nums[start]);
                ans = max(ans , mini * (end - start + 1));
            }
            else{
                end = end + 1;
                mini = min(mini , nums[end]);
                ans = max(ans , mini * (end - start + 1));
            }
            
        }
        return ans ;
    }
    int maximumScore(vector<int>& nums, int k) {
        return callgreddy(nums , k);
    }
};
