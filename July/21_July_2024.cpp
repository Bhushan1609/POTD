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
void dfs(int node,vector<int>adj[],vd<int>&visited,stack<int>&st,bool &cycle){
    visited[node]=1;
    for(auto i:adj[node]){
        if(visited[i] == 0)dfs(i,adj,visited,st,cycle);
        else if(visited[i] == 1){
            cycle=true;
            return ;
        }
    }
    visited[node]=2;
    st.push(node);
    return ;
}
vd<int> toposort(vdd<int>&v,int k){
    vd<int>ans;
    stack<int>st;
    vd<int>visited(k+1,0);
    vector<int>adj[k+1];
    for(auto i:v)adj[i[0]].push_back(i[1]);
    bool cycle=false;
    FOR(k+1){
        if(_==0)continue;
        if(!visited[_]){
            dfs(_,adj,visited,st,cycle);
            if(cycle)return {};
        }
    }
    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
    }
    return ans;
}
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        nfs;
        vd<int>topoRow=toposort(r,k);
        vd<int>topoCol=toposort(c,k);
        if(len(topoRow)==0 or len(topoCol)==0)return {};
        vdd<int>ans(k,vd<int>(k,0));
        FOR(len(topoRow)){
            FOR(i,0,len(topoCol)){
                if(topoRow[_] == topoCol[i]){
                    ans[_][i]=topoRow[_];
                }
            }
        }
        return ans;
    }
};

class wrapper{
    boolean val;
    wrapper(boolean v){
        this.val=v;
    }
}
class Solution {
    public static void dfs(int node,List<Integer>[] adj,int[] visited,Stack<Integer> st,wrapper cycle){
        visited[node]=1;
        for(int i:adj[node]){
            if(visited[i] == 0) dfs(i,adj,visited,st,cycle);
            else if(visited[i] == 1){
                cycle.val=true;
                return ;
            }
        }
        visited[node]=2;
        st.push(node);
        return ;
    }
    public static int[] toposort(int[][] v,int k){
        int[] ans=new int[k];
        Stack<Integer>st=new Stack<>();
        int[] visited=new int[k+1];
        List<Integer>[] adj;
        adj = new ArrayList[k + 1];
        for(int i=1;i<=k;i++)adj[i]=new ArrayList<>();
        for(int i=0;i<v.length;i++)adj[v[i][0]].add(v[i][1]);
        wrapper cycle=new wrapper(false);
        for(int i=1;i<=k;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,st,cycle);
                if(cycle.val==true)return new int[0];
            }
        }
        int index=0;
        while(!st.isEmpty())ans[index++] = (st.pop());
        return ans;
    }
    public int[][] buildMatrix(int k, int[][] r, int[][] c) {
        int[] topoRow=toposort(r,k);
        int[] topoCol=toposort(c,k);
        if(topoRow.length==0 || topoCol.length==0) return new int[0][0];
        int[][] ans=new int[k][k];
        for(int i=0;i<topoRow.length;i++){
            for(int j=0;j<topoCol.length;j++){
                if(topoRow[i] == topoCol[j]){
                    ans[i][j]=topoRow[i];
                }
            }
        }
        return ans;
    }
}

/**
 * @param {number} k
 * @param {number[][]} rowConditions
 * @param {number[][]} colConditions
 * @return {number[][]}
 */
 class wrapper{
    constructor(v){
        this.val=v;
    }
}

function toposort(v,k){
    const ans= new Array(k).fill(0);
    const st=[];
    const visited= new Array(k+1).fill(0);
    let adj=Array.from({length : k+1} , () => []);
    for(let i=0;i<v.length;i++)adj[v[i][0]].push(v[i][1]);
    var cycle=new wrapper(false);
    for(let i=1;i<=k;i++){
        if(visited[i]===0){
            dfs(i,adj,visited,st,cycle);
            if(cycle.val===true)return [];
        }
    }
    let index=0;
    while(st.length)ans[index++] = (st.pop());
    return ans;
}
function dfs( node,adj,visited,st, cycle){
    visited[node]=1;
    for(let i of adj[node]){
        if(visited[i] === 0){
            dfs(i,adj,visited,st,cycle);
        }
        else if(visited[i] === 1){
            cycle.val=true;
            return;
        }
    }
    visited[node]=2;
    st.push(node);
    return ;
}
var buildMatrix = function(k, r, c) {
    const topoRow=toposort(r,k);
    const topoCol=toposort(c,k);
    if(topoRow.length==0 || topoCol.length==0) return [];
    let ans=Array.from({length : k}, () => Array(k).fill(0));
    for(let i=0;i<topoRow.length;i++){
        for(let j=0;j<topoCol.length;j++){
            if(topoRow[i] == topoCol[j]){
                ans[i][j]=topoRow[i];
            }
        }
    }
    return ans;
};




//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
long long int recursion(int index, vd<int>&arr){
    if(index>=len(arr))return 1;
    long long int ntake=recursion(index+1,arr);
    long long int take=( arr[index] * recursion(index+1,arr) )  % mod ;
    return max(take,ntake);
}
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        if(len(arr) == 1)return arr[0];
        long long int  ans1=1,negprod=1,zero=0,neg=0,div=-1e9;
        FOR(len(arr)){
            if(arr[_] == 0){
                zero++;
                continue;
            }
            if(arr[_] > 0)ans1 = (ans1 * (long long int)arr[_]) % mod;
            else {
                neg+=1;
                div=max(div,(long long int)arr[_]);
                negprod=(negprod * (long long int)arr[_]) % mod;
            }
        }
        if(zero == len(arr))return 0;
        if(neg == 1 and zero == len(arr) - 1)return 0;
        if(neg & 1)negprod=(negprod / div) % mod;
        return (ans1 * negprod ) % mod;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends


//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            int n = sc.nextInt();
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < n; i++) list.add(sc.nextInt());

            Solution obj = new Solution();
            long ans = obj.findMaxProduct(list);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends




class Solution {
    public long findMaxProduct(List<Integer> arr) {
        if(arr.size() == 1)return arr.get(0);
        int mod=1000000000 + 7;
        long    ans1=1,negprod=1,zero=0,neg=0,div=Integer.MIN_VALUE;
        for(int i=0;i<arr.size();i++){
            if(arr.get(i) == 0){
                zero++;
                continue;
            }
            if(arr.get(i) > 0)ans1 = (ans1 * (long)arr.get(i)) % mod;
            else {
                neg+=1;
                div=Math.max(div,(long)arr.get(i));
                negprod=(negprod * (long)arr.get(i)) % mod;
            }
        }
        if(zero == arr.size())return 0;
        if(neg == 1 & zero == arr.size() - 1)return 0;
        if(neg%2  == 1)negprod=(negprod / div) % mod;
        return (ans1 * negprod ) % mod;
    }
}


//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            int n = sc.nextInt();
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < n; i++) list.add(sc.nextInt());

            Solution obj = new Solution();
            long ans = obj.findMaxProduct(list);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends




class Solution {
    public long findMaxProduct(List<Integer> arr) {
        if(arr.size() == 1)return arr.get(0);
        int mod=1000000000 + 7;
        long    ans1=1,negprod=1,zero=0,neg=0,div=Integer.MIN_VALUE;
        for(int i=0;i<arr.size();i++){
            if(arr.get(i) == 0){
                zero++;
                continue;
            }
            if(arr.get(i) > 0)ans1 = (ans1 * (long)arr.get(i)) % mod;
            else {
                neg+=1;
                div=Math.max(div,(long)arr.get(i));
                negprod=(negprod * (long)arr.get(i)) % mod;
            }
        }
        if(zero == arr.size())return 0;
        if(neg == 1 & zero == arr.size() - 1)return 0;
        if(neg%2  == 1)negprod=(negprod / div) % mod;
        return (ans1 * negprod ) % mod;
    }
}