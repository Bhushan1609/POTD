//119
class Solution {
public:
    unsigned long long nCr(unsigned long long rowIndex , unsigned long long i){
        if(i == 0 or i == rowIndex) return 1;
        unsigned long long result ;
        for(int j = 1 ; j <= i ; j++){
            result *= (rowIndex)--;
            result /= j;
        }
        return result;
    }
    vector<int> getRow(int rowIndex) {
        vector <int> answer;
        for (int i = 0 ; i <= rowIndex ; i++){
            answer.push_back((int) nCr(rowIndex , i));
        }
        return answer;
    }
};
