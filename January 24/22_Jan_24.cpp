// 645. Set Mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        int a ,b;
        for(auto i : nums)m[i]++;
        for(auto i : m) if(i.second == 2) a=i.first;
        for(int i = 0 ; i < nums.size();i++){
            if(m[i+1]==0) {
                b=i+1;
                break;
            }
        }
        return {a,b};
    }
};