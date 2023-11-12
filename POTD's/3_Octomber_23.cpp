//1512
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int ,int>mpp;
        for (auto i : nums){
            if(mpp.find(i) != mpp.end()){
                cnt += mpp[i];
                mpp[i]++;
            }
            else mpp[i]++;
        }
        return cnt;
    }
};
