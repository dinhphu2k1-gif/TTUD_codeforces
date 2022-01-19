#include <bits/stdc++.h>

using namespace std;

int n, T, D;
int a[1001], t[1001];
int F[1001][1001];
int res = 0;

void input(){
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
}

void solve(){
    for (int i = 1; i <= n; i++){
        F[i][t[i]] = a[i];
        res = max(res, F[i][t[i]]);
        for (int j = max(i - D, 1); j < i; j++ ){
            for (int k = t[j]; k <= T - t[i]; k++){
                F[i][k + t[i]] = max(F[i][k + t[i]], F[j][k] + a[i]);
                res = max(res, F[i][k + t[i]]);
            }
        }
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