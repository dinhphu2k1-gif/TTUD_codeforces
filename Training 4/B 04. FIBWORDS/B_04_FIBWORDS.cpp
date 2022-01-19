#include <bits/stdc++.h>

using namespace std;

int n;
string p;
vector <string> F;
vector <int> res;
int lenP;

bool check(int l, int r, int index){
    int i = 0;
    for (int j = l; j <= r; j++){
        if (F[index][j] != p[i]) return false;
        i++;
    }
    return true;
}

void solve(){
    for (int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
        res[i] = res[i-1] + res[i-2];
        
        int len1 = F[i-1].length(), len2 = F[i-2].length();
        if (len1 + len2 >= lenP){
            int left, right;
            if (len2 < lenP){
                right = len1 + len2 - 1;
                left = len1 + len2 - lenP;
            }
            else {
                left = len1 - 1;
                right = left + lenP - 1;
            }
            while (left >= 0 && right > len1){
                if (check(left, right, i)) res[i]++;
                left--;
                right--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    F.push_back("0");
    F.push_back("1");
    while (t--){
        cin >> n;
        cin >> p;
        lenP = p.length();
        F.resize(n + 1);
        res.resize(n + 1);
        if (F[0] == p) res.push_back(1);
        else res.push_back(0);

        if (F[1] == p) res.push_back(1);
        else res.push_back(0);

        solve();
        cout << res[n];
        F.clear();
        res.clear();
    }
    
    fclose(stdin);

    return 0;
}