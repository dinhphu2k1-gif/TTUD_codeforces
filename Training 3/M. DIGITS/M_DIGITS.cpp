#include <bits/stdc++.h>

using namespace std;

int n;
int X[7]; // H0, I1, K2, U3, C4, S5, T6
int visted[10];
int res = 0; 

bool check(){
    int sum = X[0]*1000 + (X[1]- X[2] + X[3])*100 + (X[4] - 6 + X[5])*10 + (2 * X[6] - 2);
    if (sum == n) return true;
    return false;
}

void solve(int k){
    for (int i = 1; i <= 9; i++){
        if (!visted[i]){
            visted[i] = 1;
            X[k] = i;

            if (k == 6) {
                if (check()) res++;
            }
            else solve(k + 1);
            visted[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    solve(0);
    cout << res;

    return 0;
}