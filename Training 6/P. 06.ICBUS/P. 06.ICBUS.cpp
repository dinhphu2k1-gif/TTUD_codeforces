#include <bits/stdc++.h>

using namespace std;
int n;
int a[50];
int res = 0;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void solve(){
    int tmp;
    for (int i = 0; i < n - 2; i++){
        for (int j = i; j <= i + 2; j++){
            tmp += pow(a[j], 3);
        }
        res = max(tmp, res);
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    solve();
    cout << res;
    return 0;
}