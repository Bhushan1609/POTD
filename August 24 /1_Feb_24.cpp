class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>answer;
        sort(begin(nums),end(nums));
        vector<int>three;
        for(int i=0;i<nums.size();i++){
            if(three.empty()){
                three.push_back(nums[i]);
            }
            else if((i+1)%3==0){
                int first=three[0];
                int second=three[1];
                if((nums[i]-first)>k or (nums[i]-second)>k) return {};
                three.push_back(nums[i]);
                answer.push_back(three);
                three.clear();
            }
            else{
                int last=three.back();
                if((nums[i]-last)>k) return {};
                three.push_back(nums[i]);
            }
        }
        return answer;
    }
};