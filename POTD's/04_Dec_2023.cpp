//2264
class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        for (int i = 0; i < num.size()-2 ; i++){
            if( (num[i] == num[i+1]) and (num[i+1] == num[i+2]) ){
                if(s.size() == 0){
                    int t = 3;
                    while(t--) s.push_back(num[i]);
                }
                else if(s[0] < num[i]){
                    int t = 3;
                    s.clear();
                    while(t--) s.push_back(num[i]);
                }
            }
        }
        return s;
    }
};
