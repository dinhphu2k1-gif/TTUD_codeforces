#include <bits/stdc++.h>

using namespace std;
int n , m;
vector <vector <int>> edge;
vector <int> parent;
vector <pair<int, int>> bridges;
int num[100005], low[100005];
bool visited[100005];
int res = 0;
int cnt = 0;

void input(){
    cin >> n >> m;
    edge.resize(n + 1);
    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}

void dfs(int u, int p){
    num[u] = low[u] = ++cnt;

    for (int v : edge[u]){
        if (v == p) continue; // khong xet dinh cha
        if (num[v] == 0){
            dfs(v, u);
            low[v] = min(low[v], low[u]);
        }
        else {
            low[v] = min(low[v], num[u]);
            
        }

        if (num[u] < low[v]) bridges.push_back({u, v});
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    for (int i = 1; i <= n; i++){
        if (num[i] == 0) dfs(i, 0);
    }
    for (int i = 0; i < bridges.size(); i++){
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }

    return 0;
}