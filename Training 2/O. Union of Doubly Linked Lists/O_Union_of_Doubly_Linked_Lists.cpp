#include <bits/stdc++.h>

using namespace std;
int n;
int l[107], r[107];
int cnt = 0;
int app[107];
deque<int> A[107];
void slv(int u)
{
    int v = l[u];
    cnt++;
    app[u] = cnt;
    app[v] = cnt;
    A[cnt].push_back(u);
    if (v != 0)
        A[cnt].push_front(v);
    while (1)
    {
        v = l[v];
        if (v == 0)
            break;
        app[v] = cnt;
        A[cnt].push_front(v);
    }
    v = r[u];
    app[v] = cnt;
    if (v != 0)
        A[cnt].push_back(v);
    while (1)
    {
        v = r[v];
        if (v == 0)
            break;
        app[v] = cnt;
        A[cnt].push_back(v);
    }
}
int main()
{
    // freopen("a.inp","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        l[i] = x;
        r[i] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        if (app[i] == 0)
        {
            slv(i);
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        int u = A[i].back();
        int v = A[i + 1].front();
        r[u] = v;
        l[v] = u;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " " << r[i] << endl;
    }
    return 0;
}