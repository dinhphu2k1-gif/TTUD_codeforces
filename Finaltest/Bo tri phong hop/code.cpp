#include <bits/stdc++.h>

using namespace std;
int n;
vector <pair<pair<int, int>, int>> arr;
int res = 0;
int cnt = 0;

void input(){
    cin >> n;
    int tmp1, tmp2, tmp3;
    for (int i = 0; i < n; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        arr.push_back({{tmp1, tmp2}, tmp3});
    }

    sort(arr.begin(), arr.end());
    // for (int i = 0; i < n; i++){
    //     cout << arr[i].first.first  << " " << arr[i].first.second << " " << arr[i].second << endl;
    // }
}

void solve(int end, int index, int m){
    if (index >= n){
        res = max(res, m);
        return ;
    }

    for (int i = index + 1; i < n; i++){
        if (arr[i].first.first > end ){
            solve(arr[i].first.second, i, m + arr[i].second);
        }
        else {
            res = max(res, m);
            // return ;
        }
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    for (int i = 0; i < n; i++){
        solve(arr[i].first.second, i, arr[i].second);
    }

    // solve();
    cout << res;

    return 0;
}