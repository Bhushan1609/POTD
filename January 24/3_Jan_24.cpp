class Solution {
public:
    int callbrute(vector <string>& bank){
        if(bank.size() == 1) return 0;
        int recent = 0 , laserBeams = 0 , startFrom = 0;
        bool found = false;
        for (int i = 0 ; i < bank.size() ; i++){
            string s = bank[i];
            for (auto j : s){
                if(j == '1') {
                    found = true;
                    recent++;
                }
            }
            if(found == true){
                // cout << "Recent : " << recent << endl;
                // cout << "StartFrom : " << i+1 << endl;
                startFrom = i+1;
                break;
            }
        }
        for (int i = startFrom; i < bank.size() ; i++){
            int current = 0;
            string s = bank[i];
            bool found = false;
            for (int j = 0 ; j < s.size() ; j++){
                if(s[j] == '1') {
                    found = true;
                    current++;
                }
            }
            if(found == true){
                laserBeams += (current*recent);
                // cout << "At i : " << i << " " << laserBeams << endl;
                // cout << "Current : " << current << " " << recent << endl;
                recent = current;
                // cout << "ARecent : " << recent << endl;
            }
        }
        return laserBeams;
    }
    int numberOfBeams(vector<string>& bank) {
        return callbrute(bank);
    }
};