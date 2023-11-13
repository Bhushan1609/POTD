// 229
class Solution {
public:
    //Follow up: Could you solve the problem in linear time and in O(1) space?
    //Using "Moores Voting Algorithm"
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 , cnt2 , ele1 , ele2;
        cnt1 = cnt2 = ele1 = ele2 = 0;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            if(cnt1 == 0 and ele2 != nums[i]){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 and ele1 != nums[i]){
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (int i = 0 ; i < n ; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        vector <int> answer;
        if(cnt1 > n/3 ){
            answer.push_back(ele1);
        }
        if(cnt2 > n/3 and ele2 != ele1) answer.push_back(ele2);
        return answer;
    }
};
