#include <bits/stdc++.h>

using namespace std;

int n;
string arr;

void solve(){
    int index = n - 1;
    int mark = 1;
    while (index >= 0 && mark){
        mark = 0;
        if (arr[index] == '0'){
            arr[index] = '1';
        }
        else {
            arr[index] = '0';
            mark = 1;
            index--;
        }
    }
    if (index < 0) cout << -1;
    else cout << arr;
}


int main(){
    // freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> arr;
    // fclose(stdin);

    solve();

    return 0;
}