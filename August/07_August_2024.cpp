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

class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int,string>belowTen={
            {1,"One"},
            {2,"Two"},
            {3,"Three"},
            {4,"Four"},
            {5,"Five"},
            {6,"Six"},
            {7,"Seven"},
            {8,"Eight"},
            {9,"Nine"}
        },
        belowTwenty={
            {10,"Ten"},
            {11,"Eleven"},
            {12,"Twelve"},
            {13,"Thirteen"},
            {14,"Fourteen"},
            {15,"Fifteen"},
            {16,"Sixteen"},
            {17,"Seventeen"},
            {18,"Eighteen"},
            {19,"Nineteen"},
            {20,"Twenty"}
        },
        belowHundred={
            {1,"Ten"},
            {2,"Twenty"},
            {3,"Thirty"},
            {4,"Forty"},
            {5,"Fifty"},
            {6,"Sixty"},
            {7,"Seventy"},
            {8,"Eighty"},
            {9,"Ninety"}
        };
        function<string(int)>recursion=[&](int number)->string{
            if(number<10) return belowTen[number];
            if(number<20) return belowTwenty[number];
            if(number<100) return belowHundred[number/10]+((number%10) ? " "+recursion(number%10) : "");
            if(number<1000) return recursion(number/100)+" Hundred"+((number%100) ? " "+recursion(number%100):"");
            if(number<1000000) return recursion(number/1000)+" Thousand"+((number%1000) ? " "+recursion(number%1000):"");
            if(number<1000000000) return recursion(number/1000000)+" Million"+((number%1000000) ? " "+recursion(number%1000000):"");
            return recursion(number/1000000000)+" Billion"+((number%1000000000) ? " "+recursion(number%1000000000):"");  
        };
        if(num==0) return "Zero";
        return recursion(num);
    }
};



class Solution {
    private static final HashMap<Integer,String>belowTen=new HashMap<Integer,String>();
    private static final HashMap<Integer,String>belowTwenty=new HashMap<Integer,String>();
    private static final HashMap<Integer,String>belowHundred=new HashMap<Integer,String>();
    public String numberToWords(int num) {
        belowTen.put(1,"One");
        belowTen.put(2,"Two");
        belowTen.put(3,"Three");
        belowTen.put(4,"Four");
        belowTen.put(5,"Five");
        belowTen.put(6,"Six");
        belowTen.put(7,"Seven");
        belowTen.put(8,"Eight");
        belowTen.put(9,"Nine");
        belowTwenty.put(10,"Ten");
        belowTwenty.put(11,"Eleven");
        belowTwenty.put(12,"Twelve");
        belowTwenty.put(13,"Thirteen");
        belowTwenty.put(14,"Fourteen");
        belowTwenty.put(15,"Fifteen");
        belowTwenty.put(16,"Sixteen");
        belowTwenty.put(17,"Seventeen");
        belowTwenty.put(18,"Eighteen");
        belowTwenty.put(19,"Nineteen");
        belowTwenty.put(20,"Twenty");
        belowHundred.put(1,"Ten");
        belowHundred.put(2,"Twenty");
        belowHundred.put(3,"Thirty");
        belowHundred.put(4,"Forty");
        belowHundred.put(5,"Fifty");
        belowHundred.put(6,"Sixty");
        belowHundred.put(7,"Seventy");
        belowHundred.put(8,"Eighty");
        belowHundred.put(9,"Ninety");
        if(num==0) return "Zero";
        return recursion(num);
    }
    static String recursion(int number){
        if(number<10) return belowTen.get(number);
        if(number<20) return belowTwenty.get(number);
        if(number<100) return belowHundred.get(number/10)+((number%10 != 0) ? " "+recursion(number%10) : "");
        if(number<1000) return recursion(number/100)+" Hundred"+((number%100 != 0) ? " "+recursion(number%100):"");
        if(number<1000000) return recursion(number/1000)+" Thousand"+((number%1000 != 0) ? " "+recursion(number%1000):"");
        if(number<1000000000) return recursion(number/1000000)+" Million"+((number%1000000 != 0) ? " "+recursion(number%1000000):"");
        return recursion(number/1000000000)+" Billion"+((number%1000000000 != 0) ? " "+recursion(number%1000000000):"");
    }
}




/**
 * @param {number} num
 * @return {string}
 */
let belowTen=new Map();
let belowTwenty=new Map();
let belowHundred=new Map();
function recursion(number){
    if (number < 10) return belowTen.get(number);
    if (number < 20) return belowTwenty.get(number);
    if (number < 100) return belowHundred.get(Math.floor(number / 10)) + ((number % 10 !== 0) ? " " + recursion(number % 10) : "");
    if (number < 1000) return recursion(Math.floor(number / 100)) + " Hundred" + ((number % 100 !== 0) ? " " + recursion(number % 100) : "");
    if (number < 1000000) return recursion(Math.floor(number / 1000)) + " Thousand" + ((number % 1000 !== 0) ? " " + recursion(number % 1000) : "");
    if (number < 1000000000) return recursion(Math.floor(number / 1000000)) + " Million" + ((number % 1000000 !== 0) ? " " + recursion(number % 1000000) : "");
    return recursion(Math.floor(number / 1000000000)) + " Billion" + ((number % 1000000000 !== 0) ? " " + recursion(number % 1000000000) : "");
}
var numberToWords = function(num) {
    if(num===0) return "Zero";
    
    belowTen.set(1,"One");
    belowTen.set(2,"Two");
    belowTen.set(3,"Three");
    belowTen.set(4,"Four");
    belowTen.set(5,"Five");
    belowTen.set(6,"Six");
    belowTen.set(7,"Seven");
    belowTen.set(8,"Eight");
    belowTen.set(9,"Nine");
    belowTwenty.set(10,"Ten");
    belowTwenty.set(11,"Eleven");
    belowTwenty.set(12,"Twelve");
    belowTwenty.set(13,"Thirteen");
    belowTwenty.set(14,"Fourteen");
    belowTwenty.set(15,"Fifteen");
    belowTwenty.set(16,"Sixteen");
    belowTwenty.set(17,"Seventeen");
    belowTwenty.set(18,"Eighteen");
    belowTwenty.set(19,"Nineteen");
    belowTwenty.set(20,"Twenty");
    belowHundred.set(1,"Ten");
    belowHundred.set(2,"Twenty");
    belowHundred.set(3,"Thirty");
    belowHundred.set(4,"Forty");
    belowHundred.set(5,"Fifty");
    belowHundred.set(6,"Sixty");
    belowHundred.set(7,"Seventy");
    belowHundred.set(8,"Eighty");
    belowHundred.set(9,"Ninety");
    return recursion(num);
};