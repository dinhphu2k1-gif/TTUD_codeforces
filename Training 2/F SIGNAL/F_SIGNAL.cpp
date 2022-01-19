#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int n, b, tmp;
    vector <int> arr;
    cin >> n >> b;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    vector <int> L, R;
    L.resize(n);
    R.resize(n);
    L[0] = arr[0];
    R[n-1] = arr[n-1];
    for(int i = 1; i < n - 1; i++) {
        L[i] = max(arr[i], L[i-1]);
        R[n-i-1] = max(arr[n-i-1], R[n-i]);
    }

    int ans = -1;

    for (int i = 1; i < n - 1; i++) {
        if (L[i-1] - arr[i] >= b && R[i+1] - arr[i] >= b){
            ans = max(ans, L[i-1] - arr[i] + R[i+1] - arr[i]);
        }
    }
    cout << ans;

    // fclose(stdin);

    return 0;
}