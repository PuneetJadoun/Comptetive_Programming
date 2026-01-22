
// use to calculate the number of integers up to n that are relatively prime to n.
// Time Complexity: O(√n)
// Space Complexity: O(1)
// used in Eulers theorem


ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


// Modular Inverse — Comparison Table
// Method	Works When	Used In
// Fermat	MOD is prime	Most CP problems
// Euler	gcd(a, m) = 1	General case
// Extended Euclid	Any gcd = 1	Non-prime mod