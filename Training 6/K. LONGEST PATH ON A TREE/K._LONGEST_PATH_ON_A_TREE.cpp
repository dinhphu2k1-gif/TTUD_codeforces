#include <bits/stdc++.h>

using namespace std;
int m;
int f[100005][3];
vector <pair<int , int >> edge[100005];
int res = 0;

void input(){
    cin >> m;
    int x, y, z;
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        edge[y].push_back({x, z});
    }
}

void dfs(int x, int parent){ // dfs cua diem x va cha cua x la parent
    f[x][0] = f[x][1] = 0;  //f[x][0] va f[x][1] la 2 duong dai nhat cua x di xuong

    for (auto w : edge[x]){
        int y = w.first;
        int z = w.second;

        if (y == parent) continue;
        dfs(y, x);

        z += f[y][0];  // la duong dai nhat theo huong y

        if (z > f[x][0]){
            f[x][1] = f[x][0];
            f[x][0] = z;
        }
        else if (z > f[x][1]){
            f[x][1] = z;
        }
    }

    res = max(res, f[x][0] + f[x][1]);
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    dfs(1, 0);
    cout << res;
    return 0;
}