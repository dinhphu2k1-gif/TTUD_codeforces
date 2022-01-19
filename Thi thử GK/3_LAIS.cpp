#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> a, b;
int res = 1;


void input(){
    cin >> n;
    int tmp;
    b.resize(n + 1);
    for (int i = 0; i < n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
}

void solve(){
    for (int i = 0; i < n; i++){
        b[i] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] * a[j] < 0 && abs(a[i]) > abs(a[j])){
                b[i] = b[j] + 1;
            }
        }
        res = max(res, b[i]);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    solve();
    cout << res;

    return 0;
}