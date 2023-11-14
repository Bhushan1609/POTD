//1425
class Solution {
public:
    map<pair<int , int> , int> mapp;
    int dpfunction(int index , int prevIndex , vector <int>& nums , int k ){
        if(index >= nums.size()) return 0;
        if(mapp.find({index , prevIndex} )!= mapp.end()){
            return mapp[{index , prevIndex}];
        }
        int take  = 0 , nottake = 0;
        if(prevIndex == -1 or abs(index - prevIndex) <= k){
            take = nums[index] + dpfunction(index + 1 , index , nums , k);
            nottake = dpfunction(index + 1 , prevIndex , nums , k);
        }
       return mapp[{index , prevIndex}] = max({take , nottake});
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int prevIndex = -1;
        int index = 0;
        int ans = dpfunction(index , prevIndex , nums, k);
        if(ans == 0) return *max_element(nums.begin() , nums.end() );
        return ans;
    }
};
