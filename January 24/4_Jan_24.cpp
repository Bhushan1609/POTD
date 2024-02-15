class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOpe=0;
        unordered_map<int,int>mapp;
        for(auto i:nums)mapp[i]++;
        for(auto &[i,j]:mapp){
            if(j==1)return -1;
            if(j%3==0){
                minOpe+=(j/3);
                mapp[i]=0;
                j=0;
            }
            else{
                j-=2;
                minOpe++;
                while(j){
                    if(j%3==0){
                        minOpe+=(j/3);
                        mapp[i]=0;
                        j=0;
                    }
                    else{
                        minOpe++;
                        j-=2;
                    }
                }
            }
        }
        return minOpe;
    }
};