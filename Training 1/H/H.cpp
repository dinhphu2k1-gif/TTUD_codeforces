#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);

    int n, m;
    int a[50], b[50];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);
    if (m > n) cout << 0;
    else {
        int i= 0, j = 0;
        while(i < n && j < m){
            if (a[i] == b[j]) j++;
            i++;
        }
        if (j >= m) cout << 1;
        else cout << 0;
    }

    return 0;
}