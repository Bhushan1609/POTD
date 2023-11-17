//1877
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        sort(nums.begin() , nums.end());
        int mini  = INT_MIN;
        while(start < end){
            mini = max(mini , nums[start]+nums[end] );
            start++;end--;
        }
        return mini;
    }
};
