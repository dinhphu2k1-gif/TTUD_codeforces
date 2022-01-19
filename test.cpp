#include <bits/stdc++.h>

using namespace std;

int arr[2000];
int res = 0;
int cnt = 0;

void solve(int lo, int hi)
{   
    cnt++;
    if (hi - lo <= 1) return ;
    else {
        solve((lo + hi) / 2, hi);
    }                    
}

int main()
{   
    for (int i = 0; i < 1024; i++){
        arr[i] = i;
    }
    solve(0, 1023);
    cout << cnt;
}