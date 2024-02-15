class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int pointer1 = 0, pointer2 = 0;
        while(pointer1 < g.size() and pointer2 < s.size()){
            if(g[pointer1] <= s[pointer2]){
                pointer1++;
                pointer2++;
            }
            else pointer2++;
        }
        return pointer1;
    }
};