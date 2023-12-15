//1662
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "" , b = "";
        for (auto i : word1){
            a.append(i);
        }
        for (auto i : word2){
            b.append(i);
        }
        return a == b;
    }
};
