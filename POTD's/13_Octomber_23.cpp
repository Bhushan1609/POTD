//746
class Solution {
public:
    int dpArray[1001];
    int dpfunction(vector <int>& cost , int n , int index){
        if(index >= n){
            return 0;
        }
        if(dpArray[index] != -1){
            return dpArray[index];
        }
        int ans1 = cost[index] + dpfunction(cost , n , index +1);
        int ans2 = cost[index] + dpfunction(cost , n , index +2);
        return dpArray[index] = min({ans1 , ans2});
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dpArray  , -1 , sizeof(dpArray));
        int ans1 =  dpfunction(cost , cost.size()  , 0);
        memset(dpArray  , -1 , sizeof(dpArray));
        int ans2 =  dpfunction(cost , cost.size()  , 1);
        return min({ans1 , ans2});
    }
};
