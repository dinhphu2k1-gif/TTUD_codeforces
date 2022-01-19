#include <bits/stdc++.h>

using namespace std;
const unsigned long long P = 1000000000 + 7;

int main(){
    int n;
    cin >> n;

    unsigned long long temp;
    vector <unsigned long long> arr;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    unsigned long long res = 0;
    for (int i = 0; i < n; i++){
        res += arr[i] % P;
        res %= P;
        // cout << res << endl;
    }
    cout << res;

    return 0;
}