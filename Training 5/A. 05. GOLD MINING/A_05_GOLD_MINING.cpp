#include <bits/stdc++.h>

using namespace std;

int n, L1, L2;
vector <int> arr;
vector <long long> F;
long long res = 0;

void input(){
    cin >> n >> L1 >> L2;
    arr.resize(n);
    F.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void solve(){
    for (int i = 0; i < n; i++){
        for (int j = i - L2; j <= i - L1; j++){
            if (j < 0) F[i] = 0;
            else F[i] = max(F[i], F[j]);
        }
        F[i] += arr[i];
        // cout << F[i] << endl;
        res = max(res, F[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve();
    cout << res;

    return 0;
}