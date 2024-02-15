class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>answer(nums.size());
        int pindex=0;
        int nindex=1;
        for(auto i:nums){
            if(i<0){
                answer[nindex]=i;
                nindex++;
                nindex++;
            }
            else if(i>0){
                answer[pindex]=i;
                pindex++;
                pindex++;
            }
        }
        return answer;
    }
};