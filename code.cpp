#include <bits/stdc++.h>
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

// Use when (a*b) may overflow long long (rare in CP, but useful)
ll modMul(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

// Use for: x^y % mod
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

bool isPowerOfTwo(int n) { return n && (!(n & (n - 1))); }
bool isPerfectSquare(ll x) { ll sr = sqrt(x); return sr * sr == x; }

/*==============================================================================
    MOD INT (Mint) + COMBINATORICS TEMPLATE
    Use when question says: "answer modulo 1e9+7" and needs factorial/nCr/division
==============================================================================*/

// Mint supports +, -, *, / automatically under MOD
template<const int MOD>
struct mint {
    int val;

    // constructor
    constexpr mint(long long x = 0) : val((x % MOD + MOD) % MOD) {}

    explicit operator int() const { return val; }

    // basic operations
    mint& operator+=(const mint &b) {
        val += b.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mint& operator-=(const mint &b) {
        val -= b.val;
        if (val < 0) val += MOD;
        return *this;
    }

    mint& operator*=(const mint &b) {
        val = 1LL * val * b.val % MOD;
        return *this;
    }

    // modular inverse using Extended Euclid (works when MOD is prime too)
    mint inv() const {
        int x = 1, y = 0, t;
        for (int a = val, b = MOD; b; swap(a, b), swap(x, y)) {
            t = a / b;
            a -= t * b;
            x -= t * y;
        }
        return mint(x);
    }

    // division in modulo => a/b = a * inv(b)
    mint& operator/=(const mint &b) {
        return *this *= b.inv();
    }

    // power: a^b % MOD
    mint power(long long b) const {
        mint a = *this, res(1);
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    // unary minus
    mint operator-() const { return val == 0 ? 0 : MOD - val; }

    // friends for easy operations
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }

    friend bool operator==(const mint &a, const mint &b) { return a.val == b.val; }
    friend bool operator!=(const mint &a, const mint &b) { return a.val != b.val; }

    friend ostream& operator<<(ostream &os, const mint &a) { return os << a.val; }
    friend istream& operator>>(istream &in, mint &a) { long long x; in >> x; a = mint(x); return in; }
};

using Mint = mint<(int)mod>;

/*------------------- Combinatorics (fac, invfac, ncr) -------------------
    Use cases:
    1) fac(n)     -> n! % MOD
    2) inv(x)     -> modular inverse of x  (1/x % MOD)
    3) invfac(n)  -> (n!)^-1 % MOD
    4) ncr(n,r)   -> C(n,r) % MOD

    Examples:
    Mint a = fac(10);              // 10! % MOD
    Mint b = ncr(5,2);             // 10
    Mint c = Mint(7) / Mint(3);    // 7 * inv(3) % MOD
    Mint ways = fac(n) / (fac(r)*fac(n-r)); // also nCr
--------------------------------------------------------------------------*/
namespace comb {
    int n = 0;
    vector<Mint> _fac{1}, _invfac{1}, _inv{0};

    void init(int m) {
        // factorials only valid until MOD-1 (because MOD prime, fac(MOD)=0)
        m = min(m, (int)mod - 1);
        if (m <= n) return;

        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++)
            _fac[i] = _fac[i - 1] * i;

        _invfac[m] = _fac[m].inv();

        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }

        n = m;
    }

    Mint fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
    Mint invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
    Mint inv(int m) { if (m > n) init(2 * m); return _inv[m]; }

    Mint ncr(int n, int r) {
        if (n < r || r < 0) return 0;
        return fac(n) * invfac(r) * invfac(n - r);
    }
}

// Direct access (no need comb:: every time)
using comb::fac;
using comb::invfac;
using comb::inv;
using comb::ncr;



 // ========================= QUICK USAGE NOTES =========================
    // 1) factorial: fac(n)
    //    Mint x = fac(5);   -> 120
    //
    // 2) nCr: ncr(n,r)
    //    Mint ways = ncr(10,3);
    //
    // 3) division in mod:
    //    Mint ans = Mint(10) / Mint(4);   // valid in MOD world
    //
    // 4) anagram count of a word:
    //    word = "aabbc" => 5!/(2!*2!)
    // ====================================================================

    // Example demo (remove in contest)
    // string s; cin >> s;

/*
    CP ka question hai solution to hoga hii
    Just think kese solve ho skta hi
    Practice ++ == contest rating ++ 
    agar smajh nahi aa rha to maths kii koi equation ya formula use krke dekh kuch na kuch to hoga hii
    agar nlogn mein ho rha to n mein traverse or binary search use krke dekh , 1e7 operations sahi chal jate hai 
    agar n mein ho rha hai to brute force soch
    agar brute force se bhi nahi ho rha to phir soch ki kya data structure use krke kar skte hai
    
*/

/*
islower(ch)   // lowercase?
isalpha(ch)   // letter?
isdigit(ch)   // digit?
tolower(ch)   // convert to lowercase
toupper(ch)   // convert to uppercase


*/


/*
// ===== CHAR <-> DIGIT / LETTER CONVERSIONS (COPY-PASTE) =====

// digit char -> int
char c1 = '7';
int d1 = c1 - '0';          // 7

// int -> digit char
int d2 = 5;
char c2 = d2 + '0';         // '5'

// lowercase char -> 0..25
char c3 = 'c';
int x1 = c3 - 'a';          // 2

// 0..25 -> lowercase char
int x2 = 2;
char c4 = x2 + 'a';         // 'c'

// uppercase char -> 0..25
char c5 = 'C';
int x3 = c5 - 'A';          // 2

// 0..25 -> uppercase char
int x4 = 2;
char c6 = x4 + 'A';         // 'C'

// lowercase -> uppercase
char c7 = 'd';
char up = c7 - 'a' + 'A';   // 'D'

// uppercase -> lowercase
char c8 = 'D';
char lo = c8 - 'A' + 'a';   // 'd'

*/


/*
// ===== HASHING TRICK (26 SIZE) : 'a' at index 0 =====

vector<int> freq(26, 0);

for(char ch : s){
    freq[ch - 'a']++;
}

// freq[0] -> count of 'a'
// freq[1] -> count of 'b'
// ...
// freq[25] -> count of 'z'

*/





 
//STL functions 

/* ---------- VECTOR ---------- */
// vector<int> v;                             // dynamic array
// v.push_back(x);            // O(1) amortized
// v.pop_back();              // O(1)
// v.size(); v.empty();       // O(1)
// v.clear();                 // O(n)
// v.front(); v.back();       // O(1)
// v[i]; v.at(i);             // O(1)
// sort(v.begin(), v.end());  // O(n log n)
// sort(v.rbegin(), v.rend());// O(n log n)
// reverse(v.begin(), v.end());// O(n)
// find(v.begin(), v.end(), x);// O(n)
// count(v.begin(), v.end(), x);// O(n)
// lower_bound(v.begin(), v.end(), x); // O(log n) (sorted)
// upper_bound(v.begin(), v.end(), x); // O(log n) (sorted)
// binary_search(v.begin(), v.end(), x);// O(log n)
// erase(unique(v.begin(), v.end()), v.end()); // O(n)

/* ---------- STRING ---------- */
// string s;
// s.size(); s.length();       // O(1)
// s.push_back(c);             // O(1)
// s.pop_back();               // O(1)
// s += "abc";                 // O(n)
// s.substr(pos, len);         // O(len)
// s.find("abc");              // O(n)
// reverse(s.begin(), s.end());// O(n)
// sort(s.begin(), s.end());   // O(n log n)
// tolower(c); toupper(c);     // O(1)
// stoi(s); stoll(s);          // O(n)
// to_string(x);               // O(log10(x))

/* ---------- SET (ordered, unique) ---------- */
// set<int> st;
// st.insert(x);               // O(log n)
// st.erase(x);                // O(log n)
// st.erase(it);               // O(1)
// st.find(x);                 // O(log n)
// st.count(x);                // O(log n)
// st.size(); st.empty();      // O(1)
// *st.begin();                // O(1)  (min)
// *st.rbegin();               // O(1)  (max)
// st.lower_bound(x);          // O(log n)
// st.upper_bound(x);          // O(log n)

/* ---------- MULTISET (ordered, duplicates) ---------- */
// multiset<int> ms;
// ms.insert(x);               // O(log n)
// ms.erase(x);                // O(log n) (ALL x)
// ms.erase(ms.find(x));       // O(log n) (ONE x)
// ms.count(x);                // O(log n + k)
// ms.lower_bound(x);          // O(log n)
// ms.upper_bound(x);          // O(log n)

/* ---------- UNORDERED_SET ---------- */
// unordered_set<int> us;
// us.insert(x);               // O(1) avg, O(n) worst
// us.erase(x);                // O(1) avg
// us.find(x); us.count(x);    // O(1) avg

/* ---------- MAP (ordered) ---------- */
// map<int,int> mp;
// mp[k] = v;                  // O(log n)
// mp.insert({k,v});            // O(log n)
// mp.erase(k);                // O(log n)
// mp.find(k);                 // O(log n)
// mp.count(k);                // O(log n)
// mp.lower_bound(k);          // O(log n)
// mp.upper_bound(k);          // O(log n)

/* ---------- UNORDERED_MAP ---------- */
// unordered_map<int,int> ump;
// ump[k]++;                   // O(1) avg
// ump.erase(k);               // O(1) avg
// ump.find(k);                // O(1) avg

/* ---------- QUEUE ---------- */
// queue<int> q;
// q.push(x); q.pop();          // O(1)
// q.front(); q.back();         // O(1)
// q.size(); q.empty();         // O(1)

/* ---------- STACK ---------- */
// stack<int> st;
// st.push(x); st.pop();        // O(1)
// st.top();                    // O(1)
// st.size(); st.empty();       // O(1)

/* ---------- PRIORITY QUEUE ---------- */
// priority_queue<int> pq;                      // max heap
// priority_queue<int,vector<int>,greater<int>> pq; // min heap
// pq.push(x);                // O(log n)
// pq.pop();                  // O(log n)
// pq.top();                  // O(1)

/* ---------- PAIR ---------- */
// pair<int,int> p = {a,b};    // O(1)
// p.first; p.second;         // O(1)

/* ---------- ALGORITHMS ---------- */
// min(a,b); max(a,b);         // O(1)
// swap(a,b);                  // O(1)
// __gcd(a,b);                 // O(log min(a,b))
// lcm(a,b);                   // O(log min(a,b))
// accumulate(v.begin(),v.end(),0LL); // O(n)
// max_element(v.begin(),v.end());    // O(n)
// min_element(v.begin(),v.end());    // O(n)
// next_permutation(v.begin(),v.end());// O(n)
// prev_permutation(v.begin(),v.end());// O(n)

/* ---------- BIT OPERATIONS ---------- */
// __builtin_popcount(x);      // O(1)
// __builtin_popcountll(x);    // O(1)
// __builtin_clz(x);           // O(1)
// __builtin_ctz(x);           // O(1)

/* ---------- IMPORTANT NOTES ---------- */
// lower_bound / upper_bound need sorted data
// set/map are always sorted (RB tree)
// unordered_* are hash based (fast avg, bad worst)
// vector erase in middle is O(n)







/*---------------------------- SOLVE FUNCTION HERE ----------------------------*/

void solve() {

   
}


/*---------------------------- MAIN FUNCTION ----------------------------------*/
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    fast_io
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}






