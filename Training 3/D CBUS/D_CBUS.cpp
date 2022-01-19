#include <bits/stdc++.h>
 
using namespace std;
 
int n, maxPas;
int matrix[50][50];
int place[50];
int res = INT_MAX;
int minc = INT_MAX;
int R;
 
void input(){
    cin >> n >> maxPas;
    for (int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            cin >> matrix[i][j];
            minc = min(minc, matrix[i][j]);
        }
    }
    R = 2*n + 1;
}
 
void solve(int k, int route, int r, int numPas){
    if (r == 1) {
        res = min(res, route + matrix[k][0]);
        return ;
    }

    if ((route + r * minc) >= res) return ;

    if (numPas < maxPas){
        for (int i = 1; i <= n; i++) {
            if(place[i] == 0){
                place[i] = 1;
 
                solve(i, route + matrix[k][i], r - 1, numPas + 1);
 
                place[i] = 0;
            }
        }
    }
    
    for (int i = n + 1; i <= 2*n; i++) {
        if (place[i] == 0){
            if (place[i - n] == 1){
                place[i] = 1;
 
                solve(i, route + matrix[k][i], r - 1, numPas - 1);
 
                place[i] = 0;
            }
            
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    
    solve(0, 0, R, 0);
    cout << res;
 
    return 0;
}