class Solution {
public:
    unordered_map<string,int>mapp;
    bool anyDuplicates(string a,string b){
        int arr[26]={0};
        for(auto i:a){
            if(arr[i-'a']>0)return true;
            arr[i-'a']++;
        }
        for(auto i:b){
            if(arr[i-'a']>0) return true;
        }
        return false;
    }
    int recursion(int index,string temp , int n,vector<string>& arr){
        if(index>=n)return temp.size();
        if(mapp.find(arr[index]) != mapp.end())return mapp[arr[index]];
        int include=0,exclude=0;
        if(anyDuplicates(arr[index],temp)){
            exclude=recursion(index+1,temp,n,arr);
        }
        else{
            exclude=recursion(index+1,temp,n,arr);
            include=recursion(index+1,temp+arr[index],n,arr);
        }
        return mapp[temp]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        return recursion(0,"",arr.size(),arr);
    }
};