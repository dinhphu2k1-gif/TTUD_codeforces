#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];
int res = 20;
int cmin = 7;
int visited[20];
int load[20];

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cmin = min(cmin, a[i]);
    }
}

void solve(int cnt, int k){
    if (k == 0){
        res = min(res, cnt);
        return;
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            if (load[cnt] + a[i] <= 6){
                load[cnt] += a[i];
                visited[i] = 1;
                solve(cnt, k - 1);
                load[cnt] -= a[i];
                visited[i] = 0;
            }
            else {
                solve(cnt+1, k);
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    solve(1, n);
    cout << res;

    return 0;
}