// Leetcode
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long ans=-1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>nums[i])ans=max(ans,sum+nums[i]);
            sum+=nums[i];
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// GFG
