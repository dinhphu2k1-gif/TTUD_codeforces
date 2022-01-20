#include <bits/stdc++.h>
#include <time.h> 

using namespace std;
int n, k;
int INF = INT_MAX;
vector<pair<int, int>> roads;
vector<vector<int>> edge;
bool visited[5005];
int matrix[5005][5005];
int res = INF;

void input()
{
    cin >> n >> k;
    roads.resize(n + 1);
    int tmp1, tmp2;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        roads[i + 1] = {tmp1, tmp2};
    }

    edge.resize(n + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            matrix[i][j] = INF;
        }
    }
}

void bfs(int u, int cnt, queue<int> &Q)
{   
    // cout << cnt << endl;
    if (cnt >= roads[u].second)
        return;
    int x = Q.front();
    Q.pop();

    for (int v : edge[x])
    {
        if (visited[v])
            continue;

        visited[v] = true;
        Q.push(v);
        matrix[u][v] = roads[u].first;
        // cout << u << " " << x << " " << v << " " << cnt << endl;
    }
    bfs(u, cnt + 1, Q);
}

void solve(int u, int weight){
    // cout << u << endl;
    if (weight > res) return;

    if (u == n){
        res = min(res, weight);
        return ;
    }

    for (int i = 1; i <= n; i++){
        if (matrix[u][i] != INF && visited[i] == false){
            visited[i] = true;
            solve(i, weight + matrix[u][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    clock_t begin = clock();

    for (int i = 1; i < n; i++)
    {
        queue<int> Q;
        Q.push(i);
        visited[i] = true;
        bfs(i, 0, Q);

        for (int i = 1; i <= n; i++)
            visited[i] = false;
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << time_spent << endl;


    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (matrix[i][j] == INF)
    //             cout << "INF"
    //                  << " ";
    //         else
    //             cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    clock_t begin2 = clock();

    visited[1] = true;
    solve(1 , 0);

    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    cout << time_spent2 << endl;
    cout << res;

    

    return 0;
}