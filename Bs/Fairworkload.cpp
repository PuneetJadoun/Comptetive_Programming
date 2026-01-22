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
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template<class T, class V> void _print(pair<T, V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T, class V> void _print(map<T, V> v);
template<class T> void _print(multiset<T> v);

template<class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

/*---------------------------- MATH UTILITY FUNCTIONS -------------------------*/
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modMul(ll a, ll b, ll mod) { ll res = 0; a %= mod; while (b) { if (b & 1) res = (res + a) % mod; a = (2 * a) % mod; b >>= 1; } return res; }
ll powermod(ll x, ll y, ll p) { ll res = 1; x %= p; while (y) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } return res; }
bool isPrime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
bool isPowerOfTwo(int n) { return n && (!(n & (n - 1))); }
bool isPerfectSquare(ll x) { ll sr = sqrt(x); return sr * sr == x; }

/*---------------------------- SOLVE FUNCTION HERE ----------------------------*/
bool poss(ll x, vll&a, ll k){
    ll workersused = 1;
    ll currworkload = 0;
    ll n = a.size();

    for(ll i = 0; i<n; i++){
        if(a[i]>x){
            return false;
        }
        else if(currworkload+a[i]<=x){
            currworkload +=a[i];
        }
        else{
            workersused++;
            currworkload  = 0;
            currworkload+=a[i];
        }
    }
    if(workersused<=k){
        return true;
    }
    else{
        return false;
    }
}


/*---------------------------- MAIN FUNCTION ----------------------------------*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fast_io
    vll a = {1,2,3,5,6,7,8,9,10,11, 17};

    ll left = 0; ll right = 1e6;
    ll ans = 0;

    while(left<=right){
        ll mid = (left+right)/2;

        if(poss(mid, a, 3)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return 0;
}
