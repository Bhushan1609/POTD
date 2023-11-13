/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
// 1095
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mountIndex = -1;
        int start = 0 ;
        int n = mountainArr.length();
        int end = n -1;
        while(start < end){
            int mid = (start + end) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        } 
        mountIndex = start;
        start = 0 ;
        end  = mountIndex;
        int ans = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(mountainArr.get(mid) == target){
                ans = mid;
                return ans;
            }
            else if(mountainArr.get(mid) < target){
               
                start = mid + 1;
            }
            else{
                 end = mid -1;
            }
        }
        if(ans == -1){
            start = mountIndex + 1;
            end = n - 1; 
            while(start <= end){
                int mid = (start + end) / 2;
                if(mountainArr.get(mid) == target){
                        ans = mid;
                        return ans;
                    }
                else if(mountainArr.get(mid) < target){ 
                     end = mid -1;
                }
                else{
                   
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
};
