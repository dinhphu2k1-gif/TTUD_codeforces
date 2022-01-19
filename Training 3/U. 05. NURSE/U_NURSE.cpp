#include <bits/stdc++.h>

using namespace std;
#define P (1000000000+7)
// int x[100];
int N, K1, K2;
int res = 0;

void solve(int k, int cnt){
    // if (cnt == 0) x[k] = 0;
    // else x[k] = 1;

    if (k == N - 1){
        if ((cnt >= K1 && cnt <= K2) || cnt == 0){
            res++;
            // for (int i = 0; i < N; i++){
            //     cout << x[i] << " ";
            // }
            // cout << endl;
        } 
        return ;
    }
    if (cnt < K1){
        solve(k + 1, cnt + 1);
    }    
    else if (cnt < K2){
        solve(k + 1, 0);
        solve(k + 1, cnt + 1);
    }     
    else {
        solve(k + 1, 0);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    cin >> N >> K1 >> K2;
    // fclose(stdin);

    solve(0, 0);
    solve(0, 1);
    
    cout << res % P;

    return 0;
}