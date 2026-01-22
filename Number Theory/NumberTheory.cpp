#include<bits/stdc++.h>
using namespace std;

// TC - sqrt(n)
// To check n is prime 
bool isPrime(long long n) {
    if(n < 2) return false; 
    for(long long i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// TC - sqrt(n)
// All Factors of n 
vector<long long> getFactors(long long n) {
    vector<long long> factors;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            if(i != n / i) factors.push_back(n / i); // avoid duplicate
        }
    }
    return factors;
}


// TC - sqrt(n)
// Prime Factors of n
vector<long long> primeFactors(long long n) {
    vector<long long> fact;
    for(long long d = 2; d * d <= n; d++) {
        while(n % d == 0) {
            fact.push_back(d);
            n /= d;
        }
    }
    if(n > 1) fact.push_back(n); // leftover prime
    return fact;
}


// TC - sqrt(n)
// Check a numnber is prime or not
bool isPrime(long long n) {
    if(n < 2) return false;
    for(long long d = 2; d * d <= n; d++) {
        if(n % d == 0) return false;
    }
    return true;
}


//TC - O(n log log n)
vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}



// TC - N loglogn
const int N = 1e7;
int spf[N];

void solve(){
    for(int i = 0; i < N; i++){
        spf[i] = i;
    }

    for(int i = 2; i * i <= N; i++){
        if(spf[i] == i){
            for(int j = i * i; j < N; j += i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

//TC - O(NloglogN)
const int N = 1e7;
int hpf[N];

void solve(){
    for(int i = 0; i < N; i++){
        hpf[i] = i;
    }

    for(int i = 2; i< N; i++){
        if(hpf[i] == i){
            for(int j = 2 * i; j < N; j += i){
                hpf[j] = i;
            }
        }
    }
}


// T.C = O(n log n)
// prime factors of n
vector<int> prime_factors;
while(n > 1){
    prime_factors.push_back(spf[n]);
    n /= spf[n];
}


//Recursive Binary Exponentiation (Modular Power)
ll helper(ll a, ll b){
    if(b == 1) return a % mod;
    if(b == 0) return 1;

    ll temp = helper(a, b / 2);
    temp = (temp * temp) % mod;
    if(b & 1){
        temp = (temp * a) % mod;
    }
    return temp;
}

//Iterative Binary Exponentiation (Modular Power)
ll helper(ll a, ll b){
    ll result = 1;
    while(b > 0){
        if(b & 1){
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b = (b >> 1);
    }
    return result;
}

//Euclidean Algorithm (GCD)
//Recursive
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

//Iterative:
int gcd(int a, int b){
    while(a){
        int t = a;
        a = b % a;
        b = t;
    }
    return b;
}


//LCM of Array using GCD
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;

    int temp = arr[0];
    for(int i = 1; i < n; i++){
        temp = (1LL * temp * arr[i]) / __gcd(temp, arr[i]);
    }

    cout << temp << endl;
}