class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        vector<int>f1(26,0),f2(26,0),digits(10,0);
        for(auto i:s){
            if(i>='0' and i<='9')digits[i-'0']++;
            else if(i>='a' and i<='z'){
                f1[i-'a']++;
            }
            else f2[i-'A']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(f1[i]) pq.push({f1[i],i+'a'});
            if(f2[i]) pq.push({f2[i],i+'A'});
            if(i<10 and digits[i]) pq.push({digits[i],i+'0'}); 
        }
        while(!pq.empty()){
            int cnt=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(cnt--) ans +=(ch);
        }
        return ans;
    }
};