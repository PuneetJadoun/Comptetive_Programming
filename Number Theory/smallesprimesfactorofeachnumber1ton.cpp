// Smallest Prime Factor for each number from 1 to n
// Time Complexity: O(n log log n)
//long long n = 1e6; // example limit
// as same as sieve of eratosthenes just we are storing the smallest prime factor for each number very intutive


vector<bool> isPrime(n + 1, true);
isPrime[0] = isPrime[1] = false;

vector<int> spf(n + 1);
for (int i = 0; i <= n; i++) spf[i] = i;   // initialize: spf[i] = i

for (long long i = 2; i <= n; i++) {
    if (isPrime[i]) {
        for (long long j = i * i; j <= n; j += i) {
            isPrime[j] = false;

            // store the smallest prime factor
            spf[j] = min(spf[j], (int)i);
        }
    }
}


