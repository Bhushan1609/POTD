//2251
class Solution {
public:
    vector <int> callbrute(vector <vector <int>> flowers , vector <int> people){
        vector <int> answer;
        for (int i = 0 ; i < people.size() ; i++){
            int num = people[i];
            int cnt = 0;
            for (int j = 0 ; j < flowers.size() ; j++){
                if(flowers[j][0] <= num and num <= flowers[j][1]) {
                    cnt++;
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }
    vector <int> calloptimal(vector <vector <int>> flowers , vector <int> people){
        vector <int> low;
        vector <int> high;
        for (int i = 0 ; i < flowers.size() ; i++){
            low.push_back(flowers[i][0]);// store the all start time of the flower blooms
            high.push_back(flowers[i][1]); // store the all died time the flowers
        }
        sort(low.begin() , low.end()); // make sure both are sorted
        sort(high.begin() , high.end());
        vector <int> answer; // answer
        for (auto k : people){
            int i = upper_bound(low.begin() , low.end() , k) -low.begin();
            int j = lower_bound(high.begin() , high.end() , k) -high.begin();
            answer.push_back(abs(j-i));
        }
        return answer;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // return callbrute(flowers , people) ; // O(n * m)
        return calloptimal(flowers , people);
    }
};
