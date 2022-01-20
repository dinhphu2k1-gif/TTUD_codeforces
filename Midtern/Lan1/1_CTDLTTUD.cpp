#include <bits/stdc++.h>

using namespace std;

int n;
int X[7]; // C0, T1, D2, L3, G4, U5
int visted[10];
int res = 0; 

bool check(){
    int sum = X[0]*100000 + (X[1])*10000 + (X[1] + X[2])*1000 + (X[3]+X[1])* 100 + (X[4]+X[5])*10 + (X[1]+X[2]);
    if (sum == n){
        int A = X[0] * 100000 + X[1] * 10000 + X[2] * 1000 + X[3] * 100 + X[4] * 10 + X[1];
        int B = X[1] * 1100 + X[5] * 10 + X[2];
        cout << A << " " << B << endl;
        return true;
    } 
    return false;
}

void solve(int k){
    // cout << k << endl;
    for (int i = 0; i <= 9; i++){
        if (!visted[i]){
            if (k <= 1 && i == 0) continue;
            X[k] = i;
            visted[i] = 1;

            if (k == 5) {
                if (check()) res++;
            }
            else solve(k + 1);
            visted[i] = 0;
        }

    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    fclose(stdin);
    solve(0);
    cout << res;

    return 0;
}