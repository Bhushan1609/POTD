//1980
class Solution {
public:
    string callbrute(vector <string>& nums ){
        unordered_set<int> st; // store all decimal made by {binary strings in set}
        for (auto i : nums){
            st.insert(stoi(i,0,2)); // converting binary string decimal number and insert in set
        }
        int n = nums.size();//n is the size of nums also size of the each string in nums
        string answer ;
        // finding decimal number which is not present in the {set}
        for (int i = 0 ; i <= n ; i++){
            if(st.find(i) == st.end()){
                answer = bitset <16> (i).to_string(); // {taking O(n)}
                return answer.substr(16-n ,n); //  convertes needed lenght
            }
        }
        return "";
    }
    //Using recursion
    void recursion(unordered_set<string>& st , string ans , int n , string& str){
        if( ans.size() >= n ) {
            return ; 
        }
        if(st.find(ans) == st.end() and ans.size() == (n-1)){
            str = ans;
            return ;
        }
        st.insert(ans);
        ans.push_back('0');
        recursion(st,ans,n,str );
        ans.pop_back();
        ans.push_back('1');
        recursion(st,ans,n,str );
        ans.pop_back();
    }
    string callbetter(vector <string>&nums){
        unordered_set<string> st(nums.begin() , nums.end()) ; // store all strings
        string ans = "";
        string str;
        st.insert(ans); // pushing empty string in set
        recursion(st,ans , nums.size()+1 , str);
        return str;
    }
    //// Cantor's Diagonal Method
    string calloptimal(vector <string>& nums){
        int n = nums.size();
        string answer;
        for (int i = 0 ; i < n ; i++){
            answer += (nums[i][i] == '0') ? '1' : '0'; 
        }
        return answer;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // return callbrute(nums); //{time} O(n^2) {space} O(n)
        // return callbetter(nums) ; // using recursion again space O (n);
        return calloptimal(nums); // {time} O (n) with constant space
    }
};
