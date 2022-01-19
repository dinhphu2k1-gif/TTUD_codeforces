#include <bits/stdc++.h>

using namespace std;

int n;
int Q, p, c;
vector <int> arr;
int ans = 0;

void input(){
    int tmp;
    cin >> n;
    arr.push_back(INT_MIN);
    for (int i = 1; i <= n; i++){
        cin >> tmp;
        arr.push_back(tmp);
        if (arr[i] != arr[i-1]) ans++;
    }
}

void solve(){
    cin >> Q;
    while (Q--){
        cin >> p >> c;
        
        if (c == arr[p]) {
            cout << ans << endl;
            continue;
        }

        //xu ly ben trai nhat
        if (p == 1){
            if (c == arr[p+1]) ans--; 
            else if (arr[p] == arr[p+1]) ans++;
        }
        //xu le ben phai nhat
        else if (p == n){
            if (c == arr[p-1]) ans--; 
            else if (arr[p] == arr[p-1]) ans++;
        }
        // xu ly o giua
        else {
            if (c == arr[p+1]) ans--; 
            else if (arr[p] == arr[p+1]) ans++;

            if (c == arr[p-1]) ans--; 
            else if (arr[p] == arr[p-1]) ans++;
        }
        arr[p] = c;

        cout << ans << endl;
        
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    solve();
    // fclose(stdin);
    return 0;
}