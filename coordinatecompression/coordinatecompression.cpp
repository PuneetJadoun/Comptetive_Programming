#include "bits/stdc++.h"
using namespace std;

/*---------------------------------- FAST IO ----------------------------------*/
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*------------------------------- TYPE ALIASES --------------------------------*/
using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.1415926535;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

/*------------------------------- STL CONTAINERS ------------------------------*/
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

/*------------------------------- SHORTCUT MACROS -----------------------------*/
#define ff first
#define ss second
#define pb push_back
#define cut pop_back
#define fr(i, st, end) for (int i = st; i <= end; i++)
#define frr(i, st, end) for (int i = st; i >= end; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pm cout << "-1\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

/*------------------------------- DEBUG SECTION -------------------------------*/
void _print(ll t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template<class T, class V> void _print(pair<T, V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T, class V> void _print(map<T, V> v);
template<class T> void _print(multiset<T> v);

template<class T, class V> void _print(pair<T, V> p) { cout << "{"; _print(p.ff); cout << ", "; _print(p.ss); cout << "}"; }
template<class T> void _print(vector<T> v) { cout << "[ "; for (T i : v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(set<T> v) { cout << "[ "; for (T i : v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(multiset<T> v) { cout << "[ "; for (T i : v) { _print(i); cout << " "; } cout << "]"; }
template<class T, class V> void _print(map<T, V> v) { cout << "[ "; for (auto i : v) { _print(i); cout << " "; } cout << "]"; }

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = "; _print(x); cout << "\n";
#else
#define debug(x)
#endif

/*---------------------------- MATH UTILITY FUNCTIONS -------------------------*/
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modMul(ll a, ll b, ll mod) { ll res = 0; a %= mod; while (b) { if (b & 1) res = (res + a) % mod; a = (2 * a) % mod; b >>= 1; } return res; }
ll powermod(ll x, ll y, ll p) { ll res = 1; x %= p; while (y) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } return res; }
bool isPrime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
bool isPowerOfTwo(int n) { return n && (!(n & (n - 1))); }
bool isPerfectSquare(ll x) { ll sr = sqrt(x); return sr * sr == x; }

/*---------------------------- SOLVE FUNCTION HERE ----------------------------*/



void solve() {

    // ll n,x; cin>>n>>x;

    // vector<ll>a(n),b(n),c(n);

    // for(int i = 0; i<n; i++){
    //     cin>>a[i]>>b[i]>>c[i];
    // }

    // for(int i = 0; i<n; i++){
    //     diff[a[i]] += c[i];
    //     if(b[i]+1<1e6)
    //     diff[b[i]+1] -= c[i];
         
    // }

    // // pre sum

    // for(int i = 1; i<size; i++){
    //     diff[i] += diff[i-1];
    // }

    // ll ans = 0;

    // for(int i = 0; i<size;i++){
    //     ans+=max(x, diff[i]);
    // }   
    
    
    // cout<<ans<<endl;



    // set<ll> st;
    // for(int i = 0; i<n; i++){
    //     st.insert(a[i]);
    //     st.insert(b[i]+1);
    // }

    // ll idx = 0;
    // unordered_map<int,int>mp;
    // for(auto it:st){
    //     mp[it] = idx;
    //     idx++;
    // }

    // int compressed_size = idx;

    // vector<ll> cost(compressed_size);

    // for(int i = 0; i<n; i++){
    //     cost[mp[a[i]]]+=c[i];
    //     if(mp[b[i]]+1<compressed_size){
    //         cost[mp[b[i]+1]] -= c[i];
    //     }
    // }

    // for(int i =1; i<compressed_size; i++){
    //     cost[i] += cost[i-1];
    // }

    // vector<ll>days(st.begin(), st.end());
    // ll ans = 0;
    // for(int i =0; i<compressed_size; i++){
    //     ll span = days[i+1] - days[i];
    //     ans+=min(cost[i], x)*span;
    // }

    // cout<<ans<<endl;
    

}





/*---------------------------- MAIN FUNCTION ----------------------------------*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr); // You can still log errors separately
#endif
    fast_io
    
   int t;
   cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}











