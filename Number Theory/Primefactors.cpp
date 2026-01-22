// Naive code 
vector<int> primeFactorsNaive(int n) {
    vector<int> factors;

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    return factors;
}



// Function to perform prime factorization of a given number n
// Time Complexity: O(sqrt(n))
vector<long long> primeFactorization(long long n) {
    vector<long long> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    // If n > 1, then n itself is a prime factor (greater than sqrt(original N))
    if (n > 1)
        factorization.push_back(n);

    return factorization;
}
