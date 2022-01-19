#include <bits/stdc++.h>

using namespace std;

int N, K, S;
vector <int> a;
long long res = 0;
int cmin = INT_MAX;

void input(){
    cin >> N >> K >> S;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
}

void solve(int t, int cnt, int w){
    if (w + (K - cnt)*a[t] > S) return ;
    if (cnt == K){
        if (w == S){
            res++; 
        } 
        return ;
    }

    for (int i = t; i < N - K + cnt  + 1; i++){
        solve(i + 1, cnt+1, w + a[i]);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
   

    solve(0, 0, 0);
    cout << res;

    return 0;
}