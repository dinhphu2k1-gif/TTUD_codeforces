#include <bits/stdc++.h>
#define ii pair<int, int>
#define f first
#define s second
const int oo = 1e9 + 7;

using namespace std;

int n, m, x, y;
int matrix[1007][1007];
int r[7] = {-1, 1, 0, 0}, c[7] = {0, 0, -1, 1};
queue<ii> Q;
map<ii, int> mark;
int d[1007][1007];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
            d[i][j] = oo;
        }
    }

    d[x][y] = 1;
    Q.push(ii(x, y));
    mark[ii(x, y)] = 1;
    while (!Q.empty())
    {
        ii u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            ii v = ii(u.f + r[i], u.s + c[i]);
            if (u.f < 1 || u.f > n)
                continue;
            if (u.s < 1 || u.s > m)
                continue;
            if (mark[v] == 0)
            {
                mark[v] = 1;
                if (matrix[v.f][v.s] == 0)
                {
                    Q.push(v);
                    d[v.f][v.s] = d[u.f][u.s] + 1;
                }
            }
        }
    }
    int ans = oo;
    for (int i = 1; i <= m; i++)
    {
        if (matrix[1][i] == 0)
            ans = min(ans, d[1][i]);
        if (matrix[n][i] == 0)
            ans = min(ans, d[n][i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (matrix[i][1] == 0)
            ans = min(ans, d[i][1]);
        if (matrix[i][m] == 0)
            ans = min(ans, d[i][m]);
    }
    if (ans == oo)
        cout << -1;
    else
        cout << ans;
    
    // fclose(stdin);
    return 0;
}