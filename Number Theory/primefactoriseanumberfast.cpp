vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
    vector<pair<int, int>> ans;

    while (x != 1) {
        int prime = spf[x];
        int cnt = 0;

        while (x % prime == 0) {
            cnt++;
            x /= prime;
        }

        ans.push_back({prime, cnt});
    }

    return ans;
}

void solve() {
    int maxN = 1e6;

    vector<bool> isPrime(maxN, true);
    vector<int> spf(1e6, 1e9);

    for (long long i = 2; i < maxN; i++) {
        if (isPrime[i]) {
            spf[i] = i;

            for (long long j = i * i; j < maxN; j += i) {
                isPrime[j] = false;
                spf[j] = min(spf[j], (int)i);
            }
        }
    }

    vector<pair<int, int>> primeF = primeFactorization(36, spf);
}
// Prime Factorization of a number using Smallest Prime Factor (SPF) array
// Time Complexity: O(log n) for each number after O(n log log n) preprocessing
