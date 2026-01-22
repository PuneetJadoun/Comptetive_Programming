void solve(){
    long long x;
    cin >> x;  // assuming that x can go as high as 10^16
    double left = 1, right = 1e9;
    double ans = 1;

    // answer to be correct upto 7 decimal places
    double precision = 1e-10; // 10^(-7)

    while(right - left > precision){
        double mid = (left + right) / 2;
        if(mid <= x / mid){
            ans = mid;
            left = mid + precision;
        } else {
            right = mid - precision;
        }
    }
    cout << setprecision(12) << fixed;
    cout << ans << endl;
}



// try to use for loop after cal iterations needed in BS on decimal
void solve(){
    long long x;
    cin >> x;  // assuming that x can go as high as 10^16
    double left = 1, right = 1e9;
    double ans = 1;

    // answer to be correct upto 7 decimal places
    double precision = 1e-10; // 10^(-7)

    for(ll cnt = 0; cnt<=100; cnt++){
        double mid = (left + right) / 2;
        if(mid <= x / mid){
            ans = mid;
            left = mid + precision;
        } else {
            right = mid - precision;
        }
    }
    cout << setprecision(12) << fixed;
    cout << ans << endl;
}
