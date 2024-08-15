#include <bits/stdc++.h>
#define nfs cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;
template <class T,class P>
using pi=pair<T,P>;
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
void print(){cout << '\n';cout.flush();}
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
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__))))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
/*Read 1d/2d(type,name,size,size1)*/
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)
pi<int,int> countAndsum(vd<int>&nums, int target){
    int currSum = 0 , windowSum = 0 , totalSum =  0 , count = 0;
    int i=0, j=-1;
    while(++j  < len(nums)){

        currSum = (currSum + nums[j]) % mod;

        windowSum = ( windowSum + nums[j] * (j - i + 1) ) % mod;

        while(currSum > target){

            windowSum -= currSum;

            currSum -= nums[i++];
            
        }  
        count += (j - i + 1);

        totalSum = (totalSum + windowSum) % mod;
    }

    return {count , totalSum};
}
int sumTillK(vd<int>&nums , int k){
    int start = MIN(nums);
    int end = SUM(nums);
    while(start <= end){
        int mid = (start + end) >> 1;
        if(countAndsum(nums , mid).first >= k) end = mid - 1;
        else start = mid + 1;
    }
    auto temp = countAndsum(nums , start);
    return temp.se - start * (temp.fi - k);
}
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        return sumTillK(nums, right) - sumTillK(nums , left - 1);
    }
};




public class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T fi() {
        return first;
    }

    public U se() {
        return second;
    }

    // Setters
    public void setFirst(T first) {
        this.first = first;
    }

    public void setSecond(U second) {
        this.second = second;
    }
}
class Solution {
    public static int mod = 1000000007;
    public static Pair<Integer ,Integer> countAndsum(int[] nums, int target){
    int currSum = 0 , windowSum = 0 , totalSum =  0 , count = 0;
    int i=0, j=-1 , n = nums.length;
    while(++j  < n){

        currSum = (currSum + nums[j]) % mod;

        windowSum = ( windowSum + nums[j] * (j - i + 1) ) % mod;

        while(currSum > target){

            windowSum -= currSum;

            currSum -= nums[i++];
            
        }  
        count += (j - i + 1);

        totalSum = (totalSum + windowSum) % mod;
    }
    Pair<Integer , Integer> answer = new Pair<Integer , Integer>(count , totalSum);
    return answer ;
}
    public static int sumTillK(int[] nums , int k){
        int start = Integer.MAX_VALUE;
        int end = 0;
        int n=nums.length;
        for(int i = 0 ; i < n ; i++){
            start = Math.min(start , nums[i]);
            end  = end + nums[i];
        }
        while(start <= end){
            int mid = (start + end) >> 1;
            if(countAndsum(nums , mid).fi() >= k) end = mid - 1;
            else start = mid + 1; 
        }
        Pair<Integer , Integer> temp = countAndsum(nums , start);
        return temp.se() - start * (temp.fi() - k);
    }
    public int rangeSum(int[] nums, int n, int left, int right) {
        return sumTillK(nums , right) - sumTillK(nums , left - 1);
    }
}



/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} left
 * @param {number} right
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
const mod = 1000000007;
function countAndsum(nums,target){
    let currSum = 0 , windowSum = 0 , totalSum =  0 , count = 0;
    let i=0, j=-1 , n = nums.length;
    while(++j  < n){

        currSum = (currSum + nums[j]) % mod;

        windowSum = ( windowSum + nums[j] * (j - i + 1) ) % mod;

        while(currSum > target){

            windowSum -= currSum;

            currSum -= nums[i++];
            
        }  
        count += (j - i + 1);

        totalSum = (totalSum + windowSum) % mod;
    }
    let answer = new pair(count , totalSum);
    return answer ;
}
function sumTillK(nums,k){
    let start = Infinity;
    let end = 0;
    let n=nums.length;
    for(let i = 0 ; i < n ; i++){
        start = Math.min(start , nums[i]);
        end  = end + nums[i];
    }
    while(start <= end){
        let mid = Math.floor((start + end) >> 1);
        if(countAndsum(nums , mid).fi() >= k) end = mid - 1;
        else start = mid + 1; 
    }
    let temp = countAndsum(nums , start);
    return temp.se() - start * (temp.fi() - k);
}
var rangeSum = function(nums, n, left, right) {
    return sumTillK(nums , right) - sumTillK(nums , left - 1);
};
