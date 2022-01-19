#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
vector<vector<ull>> a;
ull k, n, m;

ull C(ull k, ull n)
{

    if (k == n || k == 0)
        return 1;
    if (k == 1)
        return n;

    // cout << (a[k][n])
    if (a[k][n] == 0)
        // cout << k << " " << n << endl;
        a[k][n] = C(k - 1, n - 1) + C(k, n - 1);

    
    return a[k][n] % m;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> m;
        a.resize(k + 1);
        for (int i = 0; i <= k; i++)
        {
            a[i].resize(n + 1);
        }

        cout << C(k, n) << endl;
        // for (int i = 1; i <= k; i++){
        //     for (int j = 1; j <= n; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        a.clear();
    }
    fclose(stdin);

    return 0;
}