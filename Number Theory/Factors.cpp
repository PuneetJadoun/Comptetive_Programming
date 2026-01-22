// Naive approach: O(n) time complexity
vector<long long> findFactorsNaive(long long n) {
    vector<long long> factors;

    for (long long d = 1; d <= n; d++) {
        if (n % d == 0) {
            factors.push_back(d);
        }
    }

    return factors;
}




// Better than naive approach: O(sqrt(n)) time complexity
vector<long long> findFactors(long long n) {
    vector<long long> factors;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            factors.push_back(d);
            if (n / d != d)  // d should be different from n / d
                factors.push_back(n / d);
        }
    }
    return factors;
}


// Observation :number of factors are odd if n is perfect square , else even 




