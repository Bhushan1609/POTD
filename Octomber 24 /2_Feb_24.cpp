class Solution {
public:
    const int mod = 1e9+1;
    vector<int> sequentialDigits(int low, int high) {
        vector<int>answer;
        for(int i=1;i<9;i++){
            int j=i;
            int store=i;
            while(j<mod){
                j=10*j + store+1;
                if(j<mod){
                    if(j>= low and j<= high) answer.push_back(j);
                    store = j%10;
                }
                else break;
                if(store==9)break;
            }
        }
        sort(begin(answer),end(answer));
        for(auto i: answer) cout<<i<<" ";
        return answer;
    }
};