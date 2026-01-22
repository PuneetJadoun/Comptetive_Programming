
// Function to compute the greatest common divisor (GCD) of two integers using the Euclidean algorithm
// Time complexity: O(log(min(a, b)))

// Intuition  -- If d divides both a and b, then d | a and d | b.
// Since a = bq + r, we have r = a − bq.
// A number that divides two integers also divides their linear combination.
// So d | (a − bq) = r.
// Hence every common divisor of (a, b) is also a divisor of (b, r),
// therefore gcd(a, b) = gcd(b, a % b).


int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


// Iterative version of the Euclidean algorithm
// Time complexity: O(log(min(a, b)))

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
