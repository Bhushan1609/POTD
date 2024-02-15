class Solution {
public:
    bool check(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int cnt1,cnt2;
        cnt1=cnt2=0;
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        for(int i=0;i<n/2;i++){
            bool put=check(s[i]);
            if(put)cnt1++;
        }
        for(int i=n/2;i<n;i++){
            bool put=check(s[i]);
            if(put)cnt2++;
        }
        return cnt1==cnt2;
    }
};