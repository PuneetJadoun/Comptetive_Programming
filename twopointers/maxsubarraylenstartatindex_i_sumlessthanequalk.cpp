



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto &it:a)cin>>it;

    int ans = 0;
    int i = 0, j = 0;

    while(j < n){
        // include the jth element in your segment
        int sum = 0;
        sum += a[j];

        while(i <= j && sum > k){   // move left pointer 1 step left
            // do something while removing a[i]
            sum -= a[i];
            i++;
        }

        // if current segment is valid, update your answer
        if(sum <= k)
            ans = max(ans, j - i + 1);

        j++;   // move right pointer 1 step right
    }
}