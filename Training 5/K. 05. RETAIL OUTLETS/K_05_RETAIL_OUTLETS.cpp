#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
int a[110];
int f[110][510]; // f[n][m]: dung toi sale thu n va dat duoc tat ca m
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void process() {
    for (int i = 1; i <= m/a[1]; i++)
        f[1][i*a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int sum = 1; sum <= m; sum++) {
            for (int j = 1; j <= sum/a[i]; j++) {
                f[i][sum] += f[i-1][sum - j * a[i]];
                f[i][sum] = f[i][sum]%mod;
            }
        }
    }
    cout << f[n][m] % mod;
}

int main()
{
    input();
    process();
}
