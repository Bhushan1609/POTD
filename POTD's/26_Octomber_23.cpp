//823
class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin() , arr.end());

        unordered_map<int ,long long> mapp;
        for (auto i : arr){
            mapp[i] = 1;
        }
        for (int i = 1 ; i < n ; i++){
            for (int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0 and mapp.find(arr[i]/arr[j]) != mapp.end()){
                    mapp[arr[i]] += (mapp[arr[j]] * mapp[arr[i] / arr[j]]);
                }
            }
        }
        long ans = 0;
        for (auto i: mapp) ans = ( (ans + i.second) % mod );
        return ans ;
    }
};
