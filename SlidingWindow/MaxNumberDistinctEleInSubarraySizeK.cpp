#include<bits/stdc++.h>
using namespace std;

// This is the template when you want something from every window of size k , works same in many questions directly 
// that index checking part is great just use both if checks and rest some logic change only 

// most of the cases sets, maps are used almost all type of problems can be solved using maps, sets, multisets + this template


// Queue / Deque Optimizations

// The elements which are added first in the window will be removed first, so sometimes we can optimize our codes by using queue / deque instead of sets.

// Example → if we have to find the first negative element for all subarrays, we can store the indices of negative elements in a queue and the index of first negative element of window will be present at the front of queue for all subarrays.
// (generally we don’t require to optimize this much, but in interviews it will leave a very good impression)


int solve(vector<int>&a, int &k){
    int ans = -1e9;
    int curr = 0;

    unordered_map<int,int>cnt;
    int n = a.size();

    for(int i = 0; i<n; i++){
        cnt[a[i]]++;

        if(cnt[a[i]] == 1)curr++;

        

        if(i>=k){
            cnt[a[i-k]]--;
            if(cnt[a[i-k]] == 0)curr--;
        }

        if(i>=k-1){
            ans = max(ans, curr);
        }
    }
    return ans;
}


int main(){
    vector<int>a = {1,1,2,3,4,5,5};

    int n = a.size();
    int k = 3;

    int ans = solve(a,k);

    cout<<ans<<endl;
    return 0;
}