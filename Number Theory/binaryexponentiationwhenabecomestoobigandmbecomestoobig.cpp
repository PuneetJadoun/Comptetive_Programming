// Binary Multiplication
// Computes (a * b) using binary method
// Time Complexity: O(log b)

// when we want a^b%m , and a or m becmoes too big , 1e18 order then 
// we can use this method to avoid overflow

// if only a becomes too big then take mod with m first then use this function use only binaryexpo , just take a%=m first .
// if m and a becomes too big then use binary multiplication function also .


// binary multiplication function can be used to multiply two numbers without overflowing directly also if needed


int binMultiply(long long a, long long b) {
    int ans = 0;

    // Loop until b becomes 0
    while (b > 0) {

        // If current bit of b is set (odd)
        // add current a to answer
        if (b & 1) {
            ans = ans + a;
        }

        // Double a (same as a = a * 2)
        a = a + a;

        // Divide b by 2 (right shift)
        b >>= 1;
    }

    return ans;
}


// Binary Exponentiation
// Computes (a ^ b) using binary exponentiation
// Uses binMultiply to avoid direct multiplication
// Time Complexity: O(log b)
int binExp(long long a, long long b) {
    int ans = 1;

    // Loop until exponent becomes 0
    while (b > 0) {

        // If current bit of b is set
        // multiply answer with current a
        if (b & 1) {
            ans = binMultiply(ans, a);
        }

        // Square a
        a = binMultiply(a, a);

        // Move to next bit of exponent
        b >>= 1;
    }

    return ans;
}



const int  M = 1e9+7;
// if b becomes too big but till 1e18 this code works fine as we can store 1e18 in long long and mod m make it inside 1e9+7

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ( res * 1LL*  a) % M;
        a = (a * 1LL * a )%M;
        b >>= 1;
    }
    return res;
}



// when b becomes too big like more than 1e18 then we can use this method to avoid overflow , till 1e18  above code will work because we can store 1e18 in long long 

const int M = 1e9 + 7;

// b <= 10^9
// b <= 10^18

int binExp(int a, long long b, int m) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    // 50^(64^32) % M
    cout << binExp(50, binExp(64, 32, M - 1), M);
}
