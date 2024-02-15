class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>answer;
        unordered_map<string,vector<string>>mapp;
        for(auto i:strs){
            string restore=i;
            sort(begin(i),end(i));
            mapp[i].push_back(restore);
        }
        for(auto &[i,j]:mapp){
            answer.push_back(j);
        }
        return answer;
    }
};