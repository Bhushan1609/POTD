class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int ans=0;
        while(nb){
            if(nb>=ne){
                ans+=ne;
                nb-=ne;
                nb++;
            }
            else{
                ans+=nb;
                nb=0;
            }
        }
        return ans;
    }
};