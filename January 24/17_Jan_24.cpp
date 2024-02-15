// 1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m1,m2;
        for(auto i :arr )m1[i]++;
        for(auto i:m1)m2[i.second]++;
        for(auto i: m2)if(i.second>1) return 0;
        return 1;
    }
};