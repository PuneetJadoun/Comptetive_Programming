#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5}; // 0-based
    int n = a.size();
    int mn = 3, mx = 5;

    // Prefix sum: pre is 1-based
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    int ans = -1e9;
    multiset<int> st;

    for (int r = mn; r <= n; r++) {
        st.insert(pre[r - mn]);

        if (r > mx) {
            st.erase(st.find(pre[r - mx - 1])); // why r-mx-1
        }

        ans = max(ans, pre[r] - *st.begin());
    }

    cout << ans << endl;

    return 0;
}
