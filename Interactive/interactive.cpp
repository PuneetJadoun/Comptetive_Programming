
// // Interactive Problem Template
// #include <bits/stdc++.h>
// using namespace std;

// /* ---------------- LOCAL SWITCH ---------------- */
// #ifndef ONLINE_JUDGE
// bool LOCAL = true;
// #else
// bool LOCAL = false;
// #endif

// int testcases = LOCAL ? 1000 : 1;
// bool print_queries = LOCAL ? true : true;
// int current_test = 0;

// /* ---------------- RANDOM ---------------- */
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int randInt(int a, int b) {
//     return a + (rng() % (b - a + 1));
// }

// /* ---------------- INTERACTOR ---------------- */
// struct Interactor {
//     int hidden_number;
//     int queries_count;
//     int max_queries = 10;

//     void init() {
//         hidden_number = randInt(1, 100);
//         queries_count = 0;
//     }

//     char make_query(int x) {
//         assert(++queries_count <= max_queries);

//         char response;
//         if (x == hidden_number) response = '=';
//         else if (x > hidden_number) response = '>';
//         else response = '<';

//         if (print_queries) cout << response << endl;
//         return response;
//     }

//     void check_answer(int x) {
//         if (x != hidden_number) {
//             if (print_queries) {
//                 cout << "Failed at test case: " << current_test << endl;
//                 cout << "Expected: " << hidden_number
//                      << " Got: " << x << endl;
//             }
//             exit(0);
//         }
//     }
// } interactor;

// /* ---------------- USER API ---------------- */
// char query(int x) {
//     if (print_queries)
//         cout << "? " << x << endl;

//     if (LOCAL)
//         return interactor.make_query(x);

//     char response;
//     cin >> response;
//     return response;
// }

// void answer(int x) {
//     if (print_queries)
//         cout << "! " << x << endl;

//     if (LOCAL)
//         interactor.check_answer(x);
// }

// /* ---------------- CODE FUNCTION ---------------- */
// void code() {
//     while (testcases--) {
//         current_test++;                 // track test case number
//         if (LOCAL) interactor.init();

//         int l = 1, r = 100, ans = -1;

//         while (l <= r) {
//             int m = (l + r) / 2;
//             char response = query(m);

//             if (response == '=') {
//                 ans = m;
//                 break;
//             }

//             if (response == '<') l = m + 1;
//             else r = m - 1;
//         }
//        // if(ans == 13)ans++;
//         answer(ans);
//     }

//     if (LOCAL && print_queries)
//         cout << "ALL STRESS TESTS PASSED\n";
// }

// /* ---------------- MAIN ---------------- */
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     code();
//     return 0;
// }
