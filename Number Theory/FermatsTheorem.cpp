ll modInverse(ll a, ll mod) {
    return binexp(a, mod - 2, mod);
}



// Modular Inverse — Comparison Table
// Method	Works When	Used In
// Fermat	MOD is prime	Most CP problems
// Euler	gcd(a, m) = 1	General case
// Extended Euclid	Any gcd = 1	Non-prime mod