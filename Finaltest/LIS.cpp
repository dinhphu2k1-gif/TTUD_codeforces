// //day con tang dai nhat (ban kho)

// #include <bits/stdc++.h>

// using namespace std;

// int n;
// vector <int> a, b;
// int res = 1;

// void input(){
//     cin >> n;
//     int tmp;
//     for (int i = 0; i < n; i++){
//         cin >> tmp;
//         a.push_back(tmp);
//     }
// }

// void solve(){
//     b.resize(n);
//     for (int i = 0; i < n; i++){
//         b[i] = 0;
//         for (int j = 0; j < i; j++){
//             if (a[i] > a[j]){
//                 b[i] = max(b[i], b[j] + 1);
//             }
//         }
//         res = max(res, b[i]);
//     }
// }

// int main(){
//     input();
//     solve();
//     // for (int i = 0; i < n; i++){
//     //     cout << b[i] << endl;
//     // }
//     cout << res + 1;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    vector<int> f(n+1), b(n+1, INT_MAX);
    b[0] = INT_MIN;
    int result = 0;
    for (int x: a) {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[k] = x;
        // cout << k << " " << x << endl;
        result = max(result, k);
    }

    cout << result;
    return 0;
}