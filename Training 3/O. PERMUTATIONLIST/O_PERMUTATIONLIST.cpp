#include <bits/stdc++.h>
#define P 1000000000

using namespace std;

int n, k;
vector <int> factorial;
vector <int> res; 

void input(){
    cin >> n >> k;
    factorial.push_back(1);

    int tmp = 1; 
    int i = 1;
    while (tmp < P){
        tmp *= i;
        factorial.push_back(tmp);
        i++;
    }
    // for (int i = 0; i < factorial.size(); i++){
    //     cout << factorial[i] << " ";
    // }
}

void solve(){
    int tmp = 1;
    // nen n > 13 thi se them cac phan tu tu 1 den ...
    for (int i = 14; i <= n; i++){
        res.push_back(tmp);
        tmp++;
    }

    vector <int> num; // luu cac phan tu con lai cua day chua dc them vao
    for (int i = 1; i < 14; i++){
        num.push_back(tmp);
        tmp++;
    }

    k--; 
    if(n > 13) tmp = 13;
    else tmp = n;
    // lay phan nguyen cua k so voi giai thua cua so vi tri con lai,do la vi tri cua phan tu can them vao, no nam trong day tao ơ tren
    for (int i = tmp - 1; i > 0; i--){
        int t = k / factorial[i];
        res.push_back(num[t]);
        num.erase(num.begin() + t);
        k = k % factorial[i];
    }
    if (k != 0) cout << -1;
    else {
        res.push_back(num[0]);
        for (int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve();

    return 0;
}