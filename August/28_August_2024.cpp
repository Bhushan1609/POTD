#include<bits/stdc++.h>
#define SPEEDUP cin.tie(NULL)->sync_with_stdio(false)

using namespace std;
using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;

template <class T,class P>
using pi=pair<T,P>;

#define INT(...)int __VA_ARGS__; IN(__VA_ARGS__) 
#define LL(...)ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...)string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...)char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...)long double __VA_ARGS__; IN(__VA_ARGS__)

void read(int &a){cin>>a;}
void read(long long &a){cin>>a;}
void read(char &a){cin>>a;}
void read(double &a){cin>>a;}
void read(long double &a){cin>>a;}
void read(string &a){cin>>a;}

template<class T,class S>void read(pair<T,S>&p){read(p.first),read(p.second);}
template<class T>void read(vector<T>&a){for(auto &i:a)read(i);}
template <class T>void read(T &a){cin >> a;}
void IN(){}
template<class Head,class... Tail>void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template<typename T,typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A){os<<A.fi<<" "<<A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os,const vector<T>&A) {
    for(size_t i=0;i<A.size();i++){
        if(i) os<<" ";
        os << A[i];
    }
    return os;
}
void print(){cout << '\n';cout.flush();}
template <class Head,class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout<<head;
    if(sizeof...(Tail)) cout<<" ";
    print(forward<Tail>(tail)...);
}

#define dbg(x...){cout<< "("<< #x<<")"<< " = (";Print(x);} 
template<typename T1>void Print(T1 t1) {cout<< t1 << " )" <<endl;} 
template<typename T1,typename... T2>
void Print(T1 t1, T2... t2) {cout<<t1<<" , ";Print(t2...);}

void YES(bool t=1) {print(t?"YES":"NO");}
void NO(bool t=1) {YES(!t);}
void Yes(bool t=1) {print(t?"Yes":"No");}
void No(bool t=1) {Yes(!t);}
void yes(bool t=1) {print(t?"yes":"no");}
void no(bool t=1) {yes(!t);}

#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v),(int)0)

template <class T>
using vd=vector<T>;
template <class T>
using vdd=vector<vd<T>>;
template <class T>
using vddd=vector<vdd<T>>;
template <class T>
using vdddd=vector<vddd<T>>;
template <class T>
using vddddd=vector<vdddd<T>>;
template <class T>
using q=queue<T>;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-const-variable"
const int mod = 1e9 + 7; 
vd<pi<int, int>> gridMoves = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
#pragma GCC diagnostic pop

/*MaxHeap*/
template <class T>
using pq=priority_queue<T>;
/*MinHeap*/
template <class T>
using pqg=priority_queue<T,vector<T>, greater<T>>;

/*FOR*/
#define FOR1(a) for(ll _=0;_<ll(a);++_)
#define FOR2(i,a) for(ll i=0;i<ll(a);++i)
#define FOR3(i,a,b) for(ll i=a;i<ll(b);++i)
#define FOR4(i,a,b,c) for (ll i =a;i<ll(b);i+=(c))
/*FOR_R*/
#define FOR1_R(a) for (ll i =(a)-1;i>=ll(0);--i)
#define FOR2_R(i,a) for (ll i=(a)-1;i>=ll(0);--i)
#define FOR3_R(i,a,b) for(ll i=(b)-1;i>=ll(a);--i)

/*Declare 2d/3d(type,name,size,size1,size2,....)*/
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__))))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

/*Read 1d/2d(type,name,size,size1)*/
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)

void dfs(int i,int j,bool &add,vdd<int>&g1,vdd<int>&g2){
    g2[i][j]=0;
    FOR(4){
        int newi=i+gridMoves[_].fi , newj=j+gridMoves[_].se;
        if(newi>=0 && newi<len(g1) && newj>=0 && newj<len(g2[0]) && g2[newi][newj]){
            if(g1[newi][newj]) dfs(newi,newj,add,g1,g2);
            else {
                add &= false;
            }
        }
    }
}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        SPEEDUP;
        int answer=0;
        FOR(i,len(g2)){
            FOR(j,len(g2[0])){
                bool add=true;
                if(g1[i][j] && g2[i][j]) {
                    dfs(i,j,add,g1,g2) , answer += (add); 
                    // dbg(i , j , add);
                }
            }
        }
        return answer;
    }
};

#ifdef LOCAL
void solve() {
    Solution Obj;
    vdd<int>g1 = {{1, 1, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0} }, 
        g2 =
        {{1, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0}
    };
    return print(Obj.countSubIslands(g1,g2));
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
#endif



public class pair<T, U> {
    private T first;
    private U second;

    public pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T fi() {
        return first;
    }

    public U se() {
        return second;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public void setSecond(U second) {
        this.second = second;
    }
}
class wrapper{
    boolean value;
    wrapper(boolean value){
        this.value=value;
    }
}
class Solution {
    public static final pair<Integer, Integer>[] gridMoves = new pair[]{
        new pair<>(-1, 0),
        new pair<>(1, 0),
        new pair<>(0, -1),
        new pair<>(0, 1)
    };
    public static void dfs(int i,int j,int n,int m,wrapper add,int[][] g1, int[][] g2){
        g2[i][j]=0;
        for(int it=0;it<4;it++){
            int newi=i+gridMoves[it].fi() , newj=j+gridMoves[it].se();
            if(newi>=0 && newi<n && newj>=0 && newj<m && g2[newi][newj]==1){
                if(g1[newi][newj]==1) dfs(newi,newj,n,m,add,g1,g2);
                else add.value &= false;
            }
        }
    }
    public int countSubIslands(int[][] g1, int[][] g2) {
        int answer=0;
        int n=g1.length,m=g1[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                wrapper add=new wrapper(true);
                if(g1[i][j]==1 && g2[i][j]==1) {
                    dfs(i,j,n,m,add,g1,g2) ;
                    if(add.value==true) answer += 1;
                }
            }
        }
        return answer;
    }
}



/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
class pair {
    constructor(first, second) {
        this.first = first;
        this.second = second;
    }
    fi() {
        return this.first;
    }
    se() {
        return this.second;
    }
    setFirst(first) {
        this.first = first;
    }
    setSecond(second) {
        this.second = second;
    }
}
class wrapper{
    constructor(value){
        this.value=value;
    }
}
var gridMoves=[
    new pair(-1, 0),
    new pair(1, 0),
    new pair(0, -1),
    new pair(0, 1)
];
function dfs(i,j,n,m,add,g1,g2){
    g2[i][j]=0;
    for(let it=0;it<4;it++){
        let newi=i+gridMoves[it].fi() , newj=j+gridMoves[it].se();
        if(newi>=0 && newi<n && newj>=0 && newj<m && g2[newi][newj]==1){
            if(g1[newi][newj]==1) dfs(newi,newj,n,m,add,g1,g2);
            else add.value &= false;
        }
    }
}
var countSubIslands = function(g1, g2) {
    let answer=0;
    let n=g1.length,m=g1[0].length;
    for(let i=0;i<n;i++){
        for(let j=0;j<m;j++){
            let add=new wrapper(true);
            if(g1[i][j]==1 && g2[i][j]==1) {
                dfs(i,j,n,m,add,g1,g2) ;
                if(add.value==true) answer += 1;
            }
        }
    }
    return answer;
};
