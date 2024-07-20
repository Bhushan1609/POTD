/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
#define nfs cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vd = vector<T>;
template <class T>
using vdd = vector<vd<T>>;
template <class T>
using vddd = vector<vdd<T>>;
template <class T>
using vdddd = vector<vddd<T>>;
template <class T>
using vddddd = vector<vdddd<T>>;
template <class T>
using q = queue<T>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
const int mod = 1e9 + 7;
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) long double __VA_ARGS__; IN(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)
void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {os << A.fi << " " << A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}
void printn() {cout << "\n";cout.flush();}
void print() {cout << ' ';cout.flush();}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
int goodPair;
vd<int> recursion(TreeNode* root,int k){
    if(!root)return {};
    if(!root->left and !root->right)return {1};
    vd<int>leftt=recursion(root->left,k);
    vd<int>rightt=recursion(root->right,k);
    FOR(len(leftt)){
        FOR(i,0,len(rightt)){
            if(leftt[_] + rightt[i] <= k)goodPair++;
        }
    }
    vd<int>takeall;
    FOR(len(leftt))takeall.pb(leftt[_] + 1);
    FOR(len(rightt))takeall.pb(rightt[_] + 1);
    return takeall;
}
class Solution {
public:
    int countPairs(TreeNode* root, int k) {
        goodPair=0;
        recursion(root,k);
        return goodPair;
    }
};




/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 class wrapper{
    int value;
    wrapper(int value){
        this.value=value;
    }
 }
class Solution {
    static List<Integer>recursion(TreeNode root,int k,wrapper goodPair){
        if(root == null)return new ArrayList<>();
        if(root.left == null && root.right==null)return new ArrayList<>(Arrays.asList(1));
        List<Integer>leftt=recursion(root.left,k,goodPair);
        List<Integer>rightt=recursion(root.right,k,goodPair);
        for(int l:leftt){
            for(int r: rightt){
                if(l + r <= k)goodPair.value++;
            }
        }
        List<Integer>takeall=new ArrayList<>();
        for(int l : leftt)takeall.add(l+1);
        for(int r : rightt)takeall.add(r+1);
        return takeall;
    }
    public int countPairs(TreeNode root, int k) {
        wrapper goodPair=new wrapper(0);
        recursion(root,k,goodPair);
        return goodPair.value;
    }
}





/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
class wrapper {
    constructor(value) {
        this.value = value;
    }
}

function recursion(root, k, goodPair) {
    if (root == null) return [];
    if (root.left == null && root.right == null) return [1];
    
    let leftt = recursion(root.left, k, goodPair);
    let rightt = recursion(root.right, k, goodPair);
    
    for (const l of leftt) {
        for (const r of rightt) {
            if (l + r <= k) goodPair.value += 1;
        }
    }
    
    let takeall = [];
    for (let l of leftt) takeall.push(l + 1);
    for (let r of rightt) takeall.push(r + 1);
    
    return takeall;
}

var countPairs = function(root, k) {
    const goodPair = new wrapper(0);
    recursion(root, k, goodPair);  // Pass `goodPair` as an argument
    return goodPair.value;
};




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
#define nfs cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vd = vector<T>;
template <class T>
using vdd = vector<vd<T>>;
template <class T>
using vddd = vector<vdd<T>>;
template <class T>
using vdddd = vector<vddd<T>>;
template <class T>
using vddddd = vector<vdddd<T>>;
template <class T>
using q = queue<T>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
const int mod = 1e9 + 7;
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) long double __VA_ARGS__; IN(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)
void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {os << A.fi << " " << A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}
void printn() {cout << "\n";cout.flush();}
void print() {cout << ' ';cout.flush();}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
int dp[100001][2];
int recursion(bool cond,int index,vd<int>&arr){
    if(index>=len(arr))return 0;
    if(dp[index][cond] != -1)return dp[index][cond];
    int ntake=recursion(cond,index+1,arr);
    int take=0;
    if(index+1 < len(arr)){
        if(cond){
            if(arr[index+1]>arr[index])take=1+recursion(!cond,index+1,arr);
            else take=ntake;
        }
        else{
            if(arr[index+1]<arr[index])take=1+recursion(!cond,index+1,arr);
            else take=ntake;
        }
    }
    return dp[index][cond]=max(take,ntake);
}
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        int ans1=0,ans2=0;
        FOR(100001)FOR(i,0,2)dp[_][i]=-1;
        FOR(len(arr))ans1=max(ans1,recursion(true,_,arr));
        FOR(100001)FOR(i,0,2)dp[_][i]=-1;
        FOR(len(arr))ans2=max(ans2,recursion(false,_,arr));
        return max(ans1,ans2)+1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java
//Back-end complete function Template for Java

class Solution {
    
    static int recursion(int cond,int index,int[] arr,int[][] dp){
    if(index>=arr.length)return 0;
    if(dp[index][cond] != -1)return dp[index][cond];
    int ntake=recursion(cond,index+1,arr,dp);
    int take=0;
    if(index+1 < arr.length){
        if(cond==1){
            if(arr[index+1]>arr[index])take=1+recursion(cond^1,index+1,arr,dp);
            else take=ntake;
        }
        else{
            if(arr[index+1]<arr[index])take=1+recursion(cond^1,index+1,arr,dp);
            else take=ntake;
        }
    }
    return dp[index][cond]=Math.max(take,ntake);
}
    public int alternatingMaxLength(int[] arr) {
        int ans1=0,ans2=0;
        int[][] dp = new int[100001][2];
        for(int i=0;i<100001;i++)for(int j=0;j<2;j++)dp[i][j]=-1;
        for(int i=0;i<arr.length;i++)ans1=Math.max(ans1,recursion(1,i,arr,dp));
        for(int i=0;i<100001;i++)for(int j=0;j<2;j++)dp[i][j]=-1;
        for(int i=0;i<arr.length;i++)ans2=Math.max(ans2,recursion(0,i,arr,dp));
        return Math.max(ans1,ans2)+1;
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String s[] = br.readLine().trim().split(" ");
            int[] nums = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                nums[i] = Integer.parseInt(s[i]);
            }
            Solution obj = new Solution();
            int ans = obj.alternatingMaxLength(nums);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

//{ Driver Code Starts
// Initial Template for javascript

// Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split('\n').map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let input_line = readLine().split(' ').map(x => parseInt(x));
        let n = input_line.length;
        let A = [];
        for (let i = 0; i < n; i++) A.push(input_line[i]);
        let obj = new Solution();
        console.log(obj.alternatingMaxLength(A));
    }
}
// } Driver Code Ends


// User function Template for javascript
/**
 * @param {number[]} arr
 * @returns {number}
 */
function recursion(cond,index,arr,dp){
    if(index>=arr.length)return 0;
    if(dp[index][cond] != -1)return dp[index][cond];
    let ntake=recursion(cond,index+1,arr,dp);
    let take=0;
    if(index+1 < arr.length){
        if(cond==1){
            if(arr[index+1]>arr[index])take=1+recursion(cond^1,index+1,arr,dp);
            else take=ntake;
        }
        else{
            if(arr[index+1]<arr[index])take=1+recursion(cond^1,index+1,arr,dp);
            else take=ntake;
        }
    }
    return dp[index][cond]=Math.max(take,ntake);
}
class Solution {
    // Function to find the maximum length of alternating subsequence
    alternatingMaxLength(arr) {
        let ans1=0,ans2=0;
        let dp = Array.from({length : 100001},() => Array(2).fill(-1));
        for(let i=0;i<arr.length;i++)ans1=Math.max(ans1,recursion(1,i,arr,dp));
        let dp1 = Array.from({length : 100001},() => Array(2).fill(-1));
        for(let i=0;i<arr.length;i++)ans2=Math.max(ans2,recursion(0,i,arr,dp1));
        return Math.max(ans1,ans2)+1;
    }
}