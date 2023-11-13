//2038
class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA , cntB;
        cntA = cntB = 0;
        for (int i = 1 ; i < colors.size()-1 ; i++){
            if(colors[i] == 'A' and colors[i-1] == 'A' and colors[i+1] == 'A') cntA++;
            if(colors[i] == 'B' and colors[i-1] == 'B' and colors[i+1] == 'B') cntB++;
        }
        if(cntA  == cntB) return false;
        if(cntA > cntB) return true;
        return false;
    }
};
