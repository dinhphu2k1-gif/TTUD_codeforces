#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> arr;
int res = 0;

void input(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void solve(){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
        }
        res = max(sum, res);
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