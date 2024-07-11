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
#define pb push_back
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
class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        stack<int>st;
        vd<int>v(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j=st.top();st.pop();
                v[i]=j;
                v[j]=i;
            }
        }
        for(int i=0,direction=1;i<s.size();i+=direction){
            if(s[i]=='(' or s[i]==')'){i=v[i]; direction*=-1;}
            else result+=s[i];
        }
        return result;
    }
};



class Solution {
    public String reverseParentheses(String s) {
        String result=new String();
        Stack<Integer>st=new Stack();
        int[] v=new int[s.length()];
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push(i);
            }
            else if(s.charAt(i)==')'){
                int j=st.pop();
                v[i]=j;
                v[j]=i;
            }
        }
        for(int i=0,direction=1;i<s.length();i+=direction){
            if(s.charAt(i)=='(' || s.charAt(i)==')'){i=v[i]; direction*=-1;}
            else result+=s.charAt(i);
        }
        return result;
    }
}




/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) {
    var result="";
    let st=[];
    let v=new Array(s.length);
    for(let i=0;i<s.length;i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            let j=st.pop();
            v[i]=j;
            v[j]=i;
        }
    }
    for(let i=0,direction=1;i<s.length;i+=direction){
        if(s[i]=='(' || s[i]==')'){i=v[i]; direction*=-1;}
        else result+=s[i];
    }
    return result;
};



//{ Driver Code Starts
// Initial Template for C++

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
vd<pi>go={{-1,0},{0,-1},{+1,0},{0,+1}};
int dfs(int i,int j,vdd<int>&grid,int &makeThisComponent){
    int n=len(grid);
    int m=len(grid[0]);
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1)return 0;
    int cnt=0;
    grid[i][j]=makeThisComponent;
    FOR(4){
        int newx=i+go[_].fi;
        int newy=j+go[_].se;
        if(newx>=0 and newy>=0 and newx<n and newy<m){
            cnt+=dfs(newx,newy,grid,makeThisComponent);
        }
    }
    return 1+cnt;
}
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int ans=0;
        int n=len(grid);
        int m=len(grid[0]);
        int makeThisComponent=2;
        bool flag=false;
        unordered_map<int,int>mapp;
        FOR(n*m){
            if(grid[_/m][_%m]==1){
                mapp[makeThisComponent]=dfs(_/m,_%m,grid,makeThisComponent);
                makeThisComponent++;
            }
        }
        FOR(n*m){
            if(grid[_/m][_%m]==0){
                flag=true;
                unordered_set<int>s;
                int subAns=0;
                FOR(i,0,4){
                    int newx=_/m+go[i].fi;
                    int newy=_%m+go[i].se;
                    if(newx>=0 and newy>=0 and newx<n and newy<m and grid[newx][newy])s.insert(grid[newx][newy]);
                }
                for(auto i:s)subAns+=mapp[i];
                ans=max(ans,1+subAns);
            }
        }
        if(!flag)ans=max(ans,n*m);
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends
\




class Solution {
    static  int dfs(int i,int j,int grid[][],int makeThisComponent){
        int n=grid.length;
        int m=grid[0].length;
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)return 0;
        int cnt=0;
        grid[i][j]=makeThisComponent;
        cnt+=dfs(i-1,j,grid,makeThisComponent)+dfs(i,j-1,grid,makeThisComponent)
        +dfs(i+1,j,grid,makeThisComponent)+dfs(i,j+1,grid,makeThisComponent);
        return 1+cnt;
    }
    public int MaxConnection(int grid[][]) {
        int ans=0;
        int n=grid.length;
        int m=grid[0].length;
        int makeThisComponent=2;
        boolean flag=false;
        Map<Integer, Integer> mapp = new HashMap<>();
        for(int i=0;i<n*m;i++){
            if(grid[i/m][i%m]==1){
                int count=dfs(i/m,i%m,grid,makeThisComponent);
                mapp.put(makeThisComponent,count);
                makeThisComponent++;
            }
        }
        for(int i=0;i<n*m;i++){
            if(grid[i/m][i%m]==0){
                flag=true;
                Set<Integer>s=new HashSet<>();
                int subAns=0;
                int newx=i/m-1;
                int newy=i%m;
                if((newx>=0) && (newy>=0) && (newx<n )&& (newy<m) && (grid[newx][newy]!=0)){
                    s.add(grid[newx][newy]);
                }
                
                newx=i/m;
                newy=i%m-1;
                if((newx>=0) && (newy>=0) && (newx<n )&& (newy<m) && (grid[newx][newy]!=0)){
                    s.add(grid[newx][newy]);
                }
                
                newx=i/m+1;
                newy=i%m;
                if((newx>=0) && (newy>=0) && (newx<n )&& (newy<m) && (grid[newx][newy]!=0)){
                    s.add(grid[newx][newy]);
                }
                
                newx=i/m;
                newy=i%m+1;
                if((newx>=0) && (newy>=0) && (newx<n )&& (newy<m) && (grid[newx][newy]!=0)){
                    s.add(grid[newx][newy]);
                }
            
                for(Integer key:s)subAns+=mapp.get(key);
                ans=Math.max(ans,1+subAns);
            }
        }
        if(!flag)ans=Math.max(ans,n*m);
        return ans;
    }
}




function dfs(i, j, grid, makeThisComponent) {
    const n = grid.length;
    const m = grid[0].length;

    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] !== 1) {
        return 0;
    }

    let cnt = 0;
    grid[i][j] = makeThisComponent;
    cnt += dfs(i - 1, j, grid, makeThisComponent) +
           dfs(i, j - 1, grid, makeThisComponent) +
           dfs(i + 1, j, grid, makeThisComponent) +
           dfs(i, j + 1, grid, makeThisComponent);

    return 1 + cnt;
}

class Solution {
    MaxConnection(n1, grid) {
        let ans = 0;
        const n = grid.length;
        const m = grid[0].length;
        let makeThisComponent = 2;
        let flag = false;
        let mapp = new Map();
        
        // Perform DFS to mark connected components
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (grid[i][j] === 1) {
                    let count = dfs(i, j, grid, makeThisComponent);
                    mapp.set(makeThisComponent, count);
                    makeThisComponent++;
                }
            }
        }
        
        // Iterate over grid to find maximum connection
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (grid[i][j] === 0) {
                    flag = true;
                    let s = new Set();
                    let subAns = 0;
                    
                    // Check all four possible neighbors
                    if (i - 1 >= 0 && grid[i - 1][j] !== 0) {
                        s.add(grid[i - 1][j]);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] !== 0) {
                        s.add(grid[i][j - 1]);
                    }
                    if (i + 1 < n && grid[i + 1][j] !== 0) {
                        s.add(grid[i + 1][j]);
                    }
                    if (j + 1 < m && grid[i][j + 1] !== 0) {
                        s.add(grid[i][j + 1]);
                    }
                    

                    for (let key of s) {
                        subAns += mapp.get(key) || 0;
                    }
                    
                    ans = Math.max(ans, 1 + subAns);
                }
            }
        }
        
        // If no empty cell found, check for maximum possible connection
        if (!flag) {
            ans = Math.max(ans, n * m);
        }
        
        return ans;
    }
}