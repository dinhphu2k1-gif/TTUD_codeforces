#include <bits/stdc++.h>
using namespace std;
int wMax, hMax, n;
int W[1000], H[1000];
int Find[1000][1000];
int waste[1000][1000];
int main()
{
    cin >> wMax >> hMax;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> W[i] >> H[i];
        Find[W[i]][H[i]]++;
    }
    for(int i = 1; i <= wMax; i++)
    {
        for(int j = 1; j <= hMax; j++)
        {
            if(Find[i][j]) continue;
            else
            {
                waste[i][j] = i*j;
                for(int w = 1; w <= i/2; w++)
                    waste[i][j] = min(waste[i][j], waste[i-w][j] + waste[w][j]);
                for(int h = 1; h <= j/2; h++)
                    waste[i][j] = min(waste[i][j], waste[i][j-h] + waste[i][h]);
            }
        }
    }
    cout << waste[wMax][hMax];
}