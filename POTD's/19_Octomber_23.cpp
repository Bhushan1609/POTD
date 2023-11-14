//844
class Solution {
public:
    //O(max(sizeof(s)  , sizeof(t)))
    //O(s.size() + t.size())
    bool callbrute(string s , string t){
        string s1 = ""; 
        string s2 = ""; 
        int n1 = s.size();
        int n2 = t.size();
        if(n1 < n2){
            for (int i = 0 ; i < n1 ; i++){
                if(s[i] == '#'){
                    if(s1.size() != 0) s1.pop_back();
                }
                else s1.push_back(s[i]);

                if(t[i] == '#'){
                    if(s2.size() != 0) s2.pop_back();
                }
                else s2.push_back(t[i]);
            }
            for (int i = n1 ; i < n2 ; i++){
                if(t[i] == '#'){
                    if(s2.size() != 0) s2.pop_back();
                }
                else s2.push_back(t[i]);
            }
        }
        else{
            for (int i = 0 ; i < n2 ; i++){
                if(s[i] == '#'){
                    if(s1.size() != 0) s1.pop_back();
                }
                else s1.push_back(s[i]);

                if(t[i] == '#'){
                    if(s2.size() != 0) s2.pop_back();
                }
                else s2.push_back(t[i]);
            }
            for (int i = n2 ; i < n1 ; i++){
                if(s[i] == '#'){
                    if(s1.size() != 0) s1.pop_back();
                }
                else s1.push_back(s[i]);
            }
        }
        return s1 == s2;
    }
    bool calloptimal(string &s , string& t){
        int skips = 0;
        int skipt = 0;
        int i = s.size() -1 ;
        int j = t.size() -1 ;
        // O(max (s.size() , t.size())) --> time
        while(i >= 0 or j >= 0){
            //checking and skipping chracter behind
            while(i >= 0){
                if(s[i] == '#') {
                    skips++; // if got hash increse count to skips
                    i--;
                }
                else if(skips > 0){
                    skips--; // skips character
                    i--;
                }
                else{ // if the string occures charcter break and
                    break;                                 //check
                }                                          // with
            }                                              // second string character
            while(j >= 0){                                 //   |
                if(t[j] == '#') {                          //   |
                    skipt++;                               //   |
                    j--;                                   //   |
                }                                          //   |
                else if(skipt > 0){                        //   |
                    skipt--;                               //   |
                    j--;                                   //   |
                }                                          //   |
                else{                                      //   |
                    break;                                 //   |
                }                                          //   |
            }                                              //   |
            char first = (i < 0)  ? '$' : s[i];  // <<-----------
            char second = (j < 0)  ? '$' : t[j];
            if(first != second) return false;

            i--;
            j--;
        }
        return true;
    }
    bool backspaceCompare(string s, string t) {
        // return callbrute(s , t) ;
        return calloptimal(s ,t);
    }
};
