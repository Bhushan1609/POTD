//2742
class Solution {
public:
    int dpArray[501][501];
    int dpfunction(vector <int>& cost , vector <int>& time , int index , int remainWalls){
        if(remainWalls <= 0) return 0; // if walls are no more means all walls are painted 
        if(index >= cost.size() ) return 1e9;// if the index is out of bound
        if(dpArray[index][remainWalls] != -1){ 
            return dpArray[index][remainWalls];
        }
        // checking with take and not take //
        // include cost of current index and 
        // remainWalls - 1(workByPaidPainter) - time[index](workByFreePainter)
        int ansWithPaint = cost[index] + dpfunction(cost,time,index+1,remainWalls-time[index]-1);
        // increase index without adding current cost[index]
        int ansWithoutPaint = dpfunction(cost , time , index + 1 , remainWalls);
        // return minimum(of both)
        return dpArray[index][remainWalls] = min({ansWithPaint , ansWithoutPaint});
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int index = 0;
        memset(dpArray , -1 , sizeof(dpArray));
        int remainWalls = cost.size();
        return dpfunction(cost , time , index , remainWalls);
    }
};
