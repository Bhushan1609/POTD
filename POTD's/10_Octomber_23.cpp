//2009
class Solution {
public:
    int callbrute(vector <int>& nums){// tle solN
        int n = nums.size();
        int mincnt = INT_MAX;
        for (int i = 0 ; i < n ; i++){
            int mini = nums[i];
            unordered_set <int> st;
            int maxi = n - 1 + mini;
            int cnt = 0;
            for (int j = 0 ; j < n ; j++){
                if(st.find(nums[j]) != st.end() or !(mini <= nums[j] and nums[j] <= maxi)) cnt++;
                st.insert(nums[j]);
            }
            mincnt = min(mincnt , cnt);
        }
        return mincnt;
    }

    int calloptimal(vector <int>& nums){
        int n = nums.size();
        // to reduce complexity from n^2 to nlogn sort the array so it give max value in log n time;
        // and also remove the duplicate element because of the upper bound 
        // sorting using ordered set 
        set <int> st(nums.begin() , nums.end());
        vector<int> temp(begin(st) , end(st)); 
        int mincnt = INT_MAX;
        for (int i = 0 ; i < temp.size() ; i++){
            int mini = temp[i];
            int maxi = n - 1 + mini;
            int cnt = 0;
            // from mini = temp[i] to maxi = upper bound (maxi)
            int j = upper_bound(temp.begin() , temp.end() , maxi) - temp.begin();
            // with all the element in the range because it is sorted
            int withRange = j-i;
            int outRange = n - withRange ;
            mincnt = min(mincnt , outRange);
        }
        return mincnt;
    }
    int minOperations(vector<int>& nums) {
        // return callbrute(nums);
        return calloptimal(nums);
    }
};
