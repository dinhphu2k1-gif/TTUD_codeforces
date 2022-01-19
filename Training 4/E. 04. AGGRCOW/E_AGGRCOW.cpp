#include <bits/stdc++.h>

using namespace std;

int N, C;
vector <int> a;
int res;
int Dmin = INT_MAX, Dmax = INT_MIN;

void input(){
    cin >> N >> C;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        a.push_back(tmp);
        Dmin = min(Dmin, tmp);
        Dmax = max(Dmax, tmp);
    }
    sort(a.begin(), a.end());
}

void solve(int left, int right){
    if (left > right) return ;
    int mid = (left + right) / 2;

    int prev = 0, cur = 1;
    int cnt = 1;
    while (cnt < C && cur < N){
        if (a[cur] - a[prev] >= mid){
            prev = cur;
            cnt++;
        }
        cur++;
    }
    // cout << cnt << " " << dis << " " << mid << endl;
    if (cnt == C){
        res = mid;
        solve(mid + 1, right);
    } 
    else solve(left, mid - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--){
        input();
        res = 0;
        solve(0, Dmax - Dmin);
        cout << res << endl;

        a.clear();
    }
    // fclose(stdin);
    return 0;
}