// Two Pointer Concept: Segment Inside a Good Segment)

// (1) Segment inside a good segment is good

// 1) Fix starting point and try to move it by 1 step forward

// → you try to find farthest ending point till segment is good.

// start to end is good

// start to end+1 is bad

// start+1 to end is also good

// 2) Fix ending point and try to move it by 1 step forward

// → we try to keep the starting point as far as possible from ending point.

// start to end is good

// start−1 to end is bad

// start−1 to end+1 is bad



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    const int INF = 1e9;
    int ans = INF;
    int sum = 0;
    int i = 0, j = 0;

    while (j < n) {
        // include the jth element
        sum += a[j];

        // while current window sum is valid (>= k)
        while (i <= j && sum >= k) {
            // update minimum length
            ans = min(ans, j - i + 1);

            // shrink window from left
            sum -= a[i];
            i++;
        }

        j++; // expand right pointer
    }

    if (ans == INF) cout << -1; // no valid subarray found
    else cout << ans;

    return 0;
}
