#include <bits/stdc++.h>
using namespace std;

//Same template for good segment technique increasing 
// increase j till cond works
// no need to dec i 
// either use map, set, sum , multiset 99%
// include the ans
// check codition shrink the window if ans not possible
// update the ans 

// Two Pointers (Fixing i vs Fixing j)
// Fix starting point (fixing i)

// i to j is the set

// When you move i forward,
// you try to move j as much as possible towards right
// until the segment is good.

// Fix ending point (fixing j)

// i to j is good
// i-1 to j is bad

// When you move j forward,
// you try to keep i pointer as much left as possible,
// but you increase i until the segment is bad.



// Very Imp


// Two Pointer Concept: Enclosing Segment)

// (2) Segment enclosing a good segment is good

// 1) Fix starting point and try to move it by 1 step forward

// → you try to keep the end point as close as possible to the start point
// until segment is good.

// start to end is good

// start to end+1 is bad

// start+1 to end+1 is also bad

// 2) Fix ending point and try to move it by 1 step forward

// → you try to find the closest starting point to the current ending point.

// start to end is good

// start+1 to end is bad

// start−1 to end is good

// start−1 to end+1 is good

//start to end+1 is good

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    int ans = 0;
    int i = 0, j = 0;
    map<int, int> freq;

    while (j < n) {
        // include the jth element
        freq[a[j]]++;

        // shrink window if more than k distinct elements
        while (i <= j && freq.size() > k) {
            freq[a[i]]--;
            if (freq[a[i]] == 0)
                freq.erase(a[i]);
            i++;
        }

        // valid segment -> update answer
        if (freq.size() <= k)
            ans = max(ans, j - i + 1);

        j++; // expand right pointer
    }

    cout << ans;
    return 0;
}
