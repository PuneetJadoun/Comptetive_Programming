#include"bits/stdc++.h"
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
#define endl "\n"

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

/*
    CP ka question hai solution to hoga hii
    Just think kese solve ho skta hi
    Practice ++ == contest rating ++ 

*/
void solve() {
    ll n; 
    cin >> n;

    string s;
    cin >> s;

    vll prea(n, 0), preb(n, 0), suffa(n, 0), suffb(n, 0), pcnt(n,0), scnt(n,0);

    // PREFIX init
    pcnt[0] = (s[0] == 'a');
    // pra[0] = 0, prb[0] = 0 (same as screenshot)

    // PREFIX DP (same as screenshot)
    for(ll i = 1; i < n; i++){
        prea[i] = prea[i-1];
        preb[i] = preb[i-1];
        pcnt[i] = pcnt[i-1];

        if(s[i] == 'a'){
            pcnt[i]++;
            preb[i] += i + 1 - pcnt[i];     // EXACT match with screenshot
        }
        else{
            prea[i] += pcnt[i];             // EXACT match with screenshot
        }
    }

    // SUFFIX init
    scnt[n-1] = (s[n-1] == 'a');

    // SUFFIX DP (same as screenshot)
    for(int i = n-2; i >= 0; i--){
        suffa[i] = suffa[i+1];
        suffb[i] = suffb[i+1];
        scnt[i] = scnt[i+1];

        if(s[i] == 'a'){
            scnt[i]++;
            suffb[i] += n - i - scnt[i];    // EXACT match with screenshot
        }
        else{
            suffa[i] += scnt[i];            // EXACT match with screenshot
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, prea[i] + suffa[i]);
        ans = min(ans, preb[i] + suffb[i]);
    }

    cout << ans << endl;
}









/*---------------------------- MAIN FUNCTION ----------------------------------*/

// To type output in terminal for input and output in terminal 
// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
// #endif
//     fast_io
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }


// input from input.txt and output in output.txt and err in Error.txt 
// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

//     fast_io;
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }


// with chrono 

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    auto start_time = chrono::high_resolution_clock::now();
#endif

    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cerr << "\nExecution time: " << duration.count() << " ms\n";
#endif

    return 0;
}


// g++ abc.cpp && .\a.exe -- to compile and run 


/*Interpret it for Codeforces
endl -- Buffer flush cout<<a<<endl<<b; -- Print a then flush buffer and b prints but remains in buffer 
"\n" -- print a
              b 
but buffer remain not empty           


Local Time	Meaning for 1s CF limit
< 0.5 s	✅ Completely safe
0.5–0.8 s	⚠️ Still fine but close
> 1.0 s	❌ Will TLE (optimize)*/










