#include <bits/stdc++.h>
#define nfs cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;
template <class T>
using pi=pair<T,T>;
#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) long double __VA_ARGS__; IN(__VA_ARGS__)
void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN(){}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {os << A.fi << " " << A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
    for(size_t i=0;i<A.size();i++){
        if(i) os<<" ";
        os << A[i];
    }
    return os;
}
void printn(){cout << "\n";cout.flush();}
void print(){cout << ' ';cout.flush();}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if(sizeof...(Tail)) cout<<" ";
    print(forward<Tail>(tail)...);
}
#define debug(x...) { cout<< "("<< #x<<")"<< " = ("; Print(x); } 
template <typename T1> void Print(T1 t1) { cout<< t1 << " )" <<endl; } 
template < typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1<<" , "; Print(t2...); }
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
const int mod=1e9+7;
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v),0)
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
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
/*Read 1d/2d(type,name,size,size1)*/
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)
vd<pi<int>>direc={
    {-1,0},
    {0,-1},
    {0,+1},
    {+1,0},
};
void dfs(int i,int j,vdd<int>&vis,vdd<int>&mat){
    vis[i][j]=true;
    for(auto &[i1,j1]:direc){
        int newi=i+i1,newj=j+j1;
        if(newi>=0 and newi<len(mat) and newj>=0 and newj<len(mat[0]) and mat[newi][newj] && !vis[newi][newj]){
            dfs(newi,newj,vis,mat);
        }
    }
}
class Solution {
public:
    int regionsBySlashes(vector<string>& g) {
        nfs;
        int answer=0;
        int n=len(g);
        vdd<int>mat(3*n,vd<int>(3*n,1));
        vdd<int>vis(3*n,vd<int>(3*n,0));
        int index1=0,index2=0;
        FOR(i,len(g)){
            index2=0;
            FOR(j,len(g[0])){
                if(g[i][j]=='/'){
                    mat[index1][index2+2]=mat[index1+1][index2+1]=mat[index1+2][index2+0]=0;
                }
                else if(g[i][j]=='\\'){
                    mat[index1][index2+0]=mat[index1+1][index2+1]=mat[index1+2][index2+2]=0;
                }
                index2 += 3;
            }
            index1 += 3;
        }
        FOR(i,len(vis)){
            FOR(j,len(vis[0])){
                if(!vis[i][j] && mat[i][j]){
                    dfs(i,j,vis,mat);
                    answer+=1;
                }
            }
        }
        return answer;
    }
};



class Solution {
    public static void dfs(int i,int j,int[][] vis,int[][] mat){
        vis[i][j]=1;
        int newi=i-1,newj=j;
        if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
            dfs(newi,newj,vis,mat);
        }
        newi=i;
        newj=j-1;
        if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
            dfs(newi,newj,vis,mat);
        }
        newi=i;
        newj=j+1;
        if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
            dfs(newi,newj,vis,mat);
        }
        newi=i+1;
        newj=j;
        if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
            dfs(newi,newj,vis,mat);
        }
    }
    public int regionsBySlashes(String[] g) {
        int answer=0;
        int n=g.length;
        int[][] mat=new int[3*n][3*n];
        int[][] vis=new int[3*n][3*n];
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                mat[i][j]=1;
            }
        }
        int index1=0,index2=0;
        for(int i=0;i<n;i++){
            index2=0;
            for(int j=0;j<g[0].length();j++){
                if(g[i].charAt(j)=='/'){
                    mat[index1][index2+2]=mat[index1+1][index2+1]=mat[index1+2][index2+0]=0;
                }
                else if(g[i].charAt(j)=='\\'){
                    mat[index1][index2+0]=mat[index1+1][index2+1]=mat[index1+2][index2+2]=0;
                }
                index2 += 3;
            }
            index1 += 3;
        }
        for(int i=0;i<vis.length;i++){
            for(int j=0;j<vis[0].length;j++){
                if(vis[i][j]==0 && mat[i][j]==1){
                    dfs(i,j,vis,mat);
                    answer+=1;
                }
            }
        }
        return answer;
    }
}


/**
 * @param {string[]} grid
 * @return {number}
 */
function dfs(i,j,vis,mat){
    vis[i][j]=1;
    let newi=i-1,newj=j;
    if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
        dfs(newi,newj,vis,mat);
    }
    newi=i;
    newj=j-1;
    if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
        dfs(newi,newj,vis,mat);
    }
    newi=i;
    newj=j+1;
    if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
        dfs(newi,newj,vis,mat);
    }
    newi=i+1;
    newj=j;
    if(newi>=0 && newi<mat.length && newj>=0 && newj<mat[0].length && mat[newi][newj]==1 && vis[newi][newj]==0){
        dfs(newi,newj,vis,mat);
    }
}
var regionsBySlashes = function(g) {
    let answer=0;
    let n=g.length;
    let mat = new Array(3 * n).fill(0).map(() => new Array(3 * n).fill(1));
    let vis = new Array(3 * n).fill(0).map(() => new Array(3 * n).fill(0));
    let index1=0,index2=0;
    for(let i=0;i<n;i++){
        index2=0;
        for(let j=0;j<g[0].length;j++){
            if(g[i][j]=='/'){
                mat[index1][index2+2]=mat[index1+1][index2+1]=mat[index1+2][index2+0]=0;
            }
            else if(g[i][j]=='\\'){
                mat[index1][index2+0]=mat[index1+1][index2+1]=mat[index1+2][index2+2]=0;
            }
            index2 += 3;
        }
        index1 += 3;
    }
    for(let i=0;i<vis.length;i++){
        for(let j=0;j<vis[0].length;j++){
            if(vis[i][j]==0 && mat[i][j]==1){
                dfs(i,j,vis,mat);
                answer+=1;
            }
        }
    }
    return answer;
};