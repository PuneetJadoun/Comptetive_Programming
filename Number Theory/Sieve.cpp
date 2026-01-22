// Very less tC almsot nloglogn -- nearly linear , if we proof it mathematically
//long long n = 1e6; // example limit

vector<bool> isPrime(n + 1, true);
isPrime[0] = isPrime[1] = false;

for (long long i = 2; i <= n; i++) {
    if (isPrime[i]) {
        for (long long j = i * i; j <= n; j += i) {
            // why iterate from i * i and not 2 * i ? because if we iterate from 2*i then we will be marking multiples of i which are already marked by smaller primes like 2,3,5,7 etc. so we start from i*i because all smaller multiples of i would have been marked by smaller primes.
            isPrime[j] = false;
        }
    }
}
