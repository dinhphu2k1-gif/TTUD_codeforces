#include <bits/stdc++.h>

using namespace std;
int N, K;
int c[3005], a[3005];
int F[3005][105];
int res = 0;
int amax = 0;

void input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
}

void solve()
{
    F[1][1] = c[1];
    for (int i = 2; i <= N; i++)
    {
        for (int j = max(1, i - amax); j < i; j++)
        {
            if (j + a[j] >= i)
            {
                for (int k = 1; k <= K; k++)
                {
                    if(F[j][k] != 0){
                        F[i][k + 1] = max(F[i][k + 1], F[j][k] + c[i]);
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    solve();
    for (int k = 2; k <= K + 1; k++){
        res = max(F[N][k], res);
        // cout << res << endl;
    }
    if (res != 0) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}