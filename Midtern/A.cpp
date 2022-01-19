#include <bits/stdc++.h>

using namespace std;
long long L, R;
long long res;

void input(){
    cin >> L >> R;   
}

void solve(){
    long long A, B;
    if (L % 2 == 0) A = L;
    else A = L + 1;

    if (R % 2 == 0) B = R;
    else B = R - 1;
    // cout << A << " " << B << endl;
    res = (B - A) / 2 + 1;
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    // cout << L << " " << R << endl;

    solve();
    cout << res;    

    return 0;
}