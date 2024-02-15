class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            int start=0;
            int end=i.size()-1;
            int flag=1;
            while(start<=end){
                if(i[start++]!=i[end--]){
                    flag=0;
                    break;
                }
            }
            if(flag)return i;
        }
        return "";
    }
};