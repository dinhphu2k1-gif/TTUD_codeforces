#include <bits/stdc++.h>

using namespace std;

int n;
string S;
int res = 0;


bool check(int L, int R){
    map <char, int> a;
    for (int i = L; i <= R; i++){
        a[S[i]] += 1;
    }
    int chan = 0, le = 0;
    map <char, int> ::iterator it = a.begin();
    for (it; it != a.end(); it++){
        if (it->second % 2 == 0) chan++;
        else le++;
    }
    // cout << L << " " << R << " " << chan << " " << le << endl;
    if ((R - L) % 2 == 0){
        if (le == 1) return true;
    }
    else {
        if (le == 0) return true;
    }

    return false;
}


void solve(){
    for (int i = 0; i < n; i++){
        for (int j = n-1; j >= i; j-- ){
            if (check (i, j)){
                res++;
                // cout << res << endl;
            } 
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    cin >> S;
    // fclose(stdin);
    solve();
    cout << res;

    return 0;
}