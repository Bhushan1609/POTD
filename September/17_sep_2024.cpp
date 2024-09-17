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

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        SPEEDUP;
        vd<string>answer;
        unordered_map<string,int>m1,m2;
        string add="";
        for(auto &i:s1){
            if(i==' '){
                m1[add]++;
                add="";
            }
            else add+=i;
        }
        m1[add]++;
        add="";
        for(auto &i:s2){
            if(i==' '){
                m2[add]++;
                add="";
            }
            else add+=i;
        }
        m2[add]++;
        add="";
        for(auto &[i,j]:m1){
            if(j==1 && m2[i]==0)answer.eb(i);
        }
        for(auto &[i,j]:m2){
           if(j==1 && m1[i]==0)answer.eb(i);
        }
        return answer;
    }
};

#ifdef LOCAL
void solve() {
    Solution Obj;
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    return print(Obj.uncommonFromSentences(s1,s2));
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







class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String,Integer>m1=new HashMap();
        Map<String,Integer>m2=new HashMap();
        String add="";
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i)==' '){
                m1.compute(add,(k,v)->(v==null)?1:v+1);
                add="";
            }else{
                add+=(s1.charAt(i));
            }
        }
        m1.compute(add,(k,v)->(v==null)?1:v+1);
        add="";
        for(int i=0;i<s2.length();i++){
            if(s2.charAt(i)==' '){
                m2.compute(add,(k,v)->(v==null)?1:v+1);
                add="";
            }else{
                add+=(s2.charAt(i));
            }
        }
        m2.compute(add,(k,v)->(v==null)?1:v+1);
        add="";
        int sz=0;
        for(Map.Entry<String,Integer>iterator:m1.entrySet() ){
            if(iterator.getValue()==1 && m2.get(iterator.getKey())==null){
                sz++;
            }
        }
        for(Map.Entry<String,Integer>iterator:m2.entrySet() ){
            iterator.getKey();
            if(iterator.getValue()==1 && m1.get(iterator.getKey())==null){
                sz++;
            }
        }
        String[] answer=new String[sz];
        sz=0;
        for(Map.Entry<String,Integer>iterator:m1.entrySet() ){
            if(iterator.getValue()==1 && m2.get(iterator.getKey())==null){
                answer[sz++]=iterator.getKey();
            }
        }
        for(Map.Entry<String,Integer>iterator:m2.entrySet() ){
            if(iterator.getValue()==1 && m1.get(iterator.getKey())==null){
                answer[sz++]=iterator.getKey();
            }
        }
        return answer;
    }
}
