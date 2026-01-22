#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

/* ---------- Fast Power ---------- */
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

/* ---------- Modular Inverse (Prime Mod) ---------- */
ll mminvprime(ll a, ll mod) {
    return binexp(a, mod - 2, mod);
}

/* ---------- Safe Multiplication ---------- */
ll mod_mul(ll a, ll b, ll mod) {
    return (a % mod * b % mod) % mod;
}

/* ---------- nCr using factorial & inverse ---------- */
ll nCr(ll n, ll r, vector<ll> &fact, vector<ll> &ifact) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], MOD), MOD);
}

/* ---------- Solve Function ---------- */
void solve() {
    int n = 10;

    vector<ll> fact(n + 1), ifact(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }

    ifact[n] = mminvprime(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }

    cout << "8C6 = " << nCr(8, 6, fact, ifact) << "\n";
}

/* ---------- Main ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
