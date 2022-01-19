#include <bits/stdc++.h>
#define ii pair<int, int>
#define f first
#define s second
using namespace std;
int n, m, d[2007][2007];
vector<ii> A, B;
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {   
        cin >> n >> m;
        A.clear();
        B.clear();
        int x;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> x;
                if (x == 1) A.push_back(ii(i, j));
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> x;
                if (x == 1) B.push_back(ii(i, j));
            }

        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
            {
                d[B[j].f - A[i].f + n][B[j].s - A[i].s + m]++;
            }
        int ans = 0;
        for (int i = 0; i <= 2 * n; i++)
            for (int j = 0; j <= 2 * m; j++)
                ans = max(ans, d[i][j]);
        cout << ans << "\n";
    }
    // fclose(stdin);
    return 0;
}