#include <bits/stdc++.h>

using namespace std;

int n, m;
int road[405][405];
int mark[25];
int res = 2147483647;
int f = 0;
int times = 0;

void input(){
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int x, y, c;

    for (int i = 1; i <= m; i++){
        cin >> x >> y >> c;
        road[x][y] = c;
    }
    mark[1] = 1;
    fclose(stdin);
}

void check(int k){
    if (f + road[k][1] < res){
        res = f + road[k][1];
    }
}

void solve(int k){
    if (f < res){
        for (int i = 2; i <= n; i++){
            if (road[k][i] != 0 && mark[i] == 0){
                f += road[k][i];
                times += 1;
                mark[i]  = 1;

                if (times == n - 1 && road[i][1] != 0) check(i);
                else solve(i);

                f-= road[k][i];
                times -= 1;
                mark[i] = 0;
            }
        }
    }
    
}

int main(){
    input();
    solve(1);

    cout << res;
    return 0;
}