#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <pair <int, int>> listP;
bool visited[505];
bool res = false;
int matrix[505][505];
stack <int> S;


int distance(pair <int, int> x, pair <int, int> y){
    return floor(sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2)));
}

void input(){
    cin >> n >> k;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        listP.push_back({x, y});
    }
    // sort(listP.begin(), listP.end());

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){

            int dis = distance(listP[i], listP[j]);
            if (dis <= k) {
                matrix[i][j] = k;
                matrix[j][i] = matrix[i][j];
            }
            
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void dfs(int u, int p){
    if (u == n - 1) {
        res = true;
        return ;
    }
    for (int i = 0; i < n; i++){
        if (i == p) continue;
        if (visited[i] || matrix[u][i] == 0) continue;

        visited[i] = true;
        dfs(i, u);
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    visited[0] = true;
    dfs(0, 0);
    
    if (res) cout << "YES";
    else cout << "NO";
    return 0;
}