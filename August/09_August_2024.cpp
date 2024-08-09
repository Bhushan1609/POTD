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
bool check(vd<int>&hashV){
    FOR(i,1,10){
        if(hashV[i]==0) return false;
    }
    return true;
}
int diagonalSum1(int i,int j,vdd<int>&g){
    return g[i][j+0]+g[i+1][j+1]+g[i+2][j+2];
}
int diagonalSum2(int i,int j,vdd<int>&g){
    return g[i][j+2]+g[i+1][j+1]+g[i+2][j+0];
}
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int answer=0,diagonal1=0,diagonal2=0,addMe,sum;
        FOR(i,len(g)-2){
            FOR(j,len(g[0])-2){
                vd<int>hashV(20,0);
                addMe=1;
                diagonal1 = diagonalSum1(i,j,g);
                diagonal2 = diagonalSum2(i,j,g);
                if(diagonal1 != diagonal2)addMe=0;
                FOR(k,i,i+3){
                    sum=0;
                    FOR(l,j,j+3){
                        sum += g[k][l];
                    }
                    if(sum != diagonal1)addMe=0;
                }
                FOR(l,j,j+3){
                    sum=0;
                    FOR(k,i,i+3){
                        if(g[k][l]>9) {
                            addMe=0;
                        }
                        hashV[g[k][l]]++;
                        sum += g[k][l];
                    }
                    if(sum != diagonal1) addMe=0;
                }
                if(addMe && check(hashV))answer+=1;
            }
        }
        return answer;
    }
};


class Solution {
    public static int diagonalSum1(int i,int j,int[][] g){
        return g[i][j+0]+g[i+1][j+1]+g[i+2][j+2];
    }
    public static int diagonalSum2(int i,int j,int[][] g){
        return g[i][j+2]+g[i+1][j+1]+g[i+2][j+0];
    }
    public static boolean check(int[] hashV){
        for(int i=1;i<10;i++){
            if(hashV[i]==0) return false;
        }
        return true;
    }
    public int numMagicSquaresInside(int[][] g) {
        int answer=0,diagonal1=0,diagonal2=0,addMe,sum;
        int n=g.length;
        int m=g[0].length;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int[] hashV=new int[20];
                addMe=1;
                diagonal1 = diagonalSum1(i,j,g);
                diagonal2 = diagonalSum2(i,j,g);
                if(diagonal1 != diagonal2)addMe=0;
                for(int k=i;k<i+3;k++){
                    sum=0;
                    for(int l=j;l<j+3;l++){
                        sum += g[k][l];
                    }
                    if(sum != diagonal1)addMe=0;
                }
                for(int l=j;l<j+3;l++){
                    sum=0;
                    for(int k=i;k<i+3;k++){
                        if(g[k][l]>9) {
                            addMe=0;
                        }
                        hashV[g[k][l]]++;
                        sum += g[k][l];
                    }
                    if(sum != diagonal1) addMe=0;
                }
                if(addMe==1 && check(hashV))answer+=1;
            }
        }
        return answer;
    }
}

/**
 * @param {number[][]} grid
 * @return {number}
 */

function diagonalSum1(i,j,g) {
    return g[i][j+0]+g[i+1][j+1]+g[i+2][j+2];
}
function diagonalSum2(i,j,g){
    return g[i][j+2]+g[i+1][j+1]+g[i+2][j+0];
}
function check(hashV){
    for(let i=1;i<10;i++){
        if(hashV[i]==0) return false;
    }
    return true;
}
var numMagicSquaresInside = function(g) {
    let answer=0,diagonal1=0,diagonal2=0,addMe,sum;
    let n=g.length;
    let m=g[0].length;
    for(let i=0;i<n-2;i++){
        for(let j=0;j<m-2;j++){
            let hahsV=new Array(20).fill(0);
            addMe=1;
            diagonal1 = diagonalSum1(i,j,g);
            diagonal2 = diagonalSum2(i,j,g);
            if(diagonal1 != diagonal2)addMe=0;
            for(let k=i;k<i+3;k++){
                sum=0;
                for(let l=j;l<j+3;l++){
                    sum += g[k][l];
                }
                if(sum != diagonal1)addMe=0;
            }
            for(let l=j;l<j+3;l++){
                sum=0;
                for(let k=i;k<i+3;k++){
                    if(g[k][l]>9) {
                        addMe=0;
                    }
                    hahsV[g[k][l]]++;
                    sum += g[k][l];
                }
                if(sum != diagonal1) addMe=0;
            }
            if(addMe==1 && check(hahsV))answer+=1;
        }
    }
    return answer;
};