class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        vector<int>v1(26,0),v2(26,0);
        for(auto i:s) v1[i-'a']++;
        for(auto i:t) v2[i-'a']++;
        for(int i=0;i<26;i++){
            v1[i]=v1[i]-v2[i];
            ans+=abs(v1[i]);
        }
        return ans/2;
    }
};