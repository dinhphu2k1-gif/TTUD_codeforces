#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, k;
vector <pair <ll, ll>> pos, neg; // positve and negative

void input(){
    // freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll a, b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (a < 0) neg.push_back({a, b});
        else pos.push_back({a, b});
    }   
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    // for (int i = 0; i < pos.size(); i++){
    //     cout << pos[i].first << " " << pos[i].second << endl;
    // }
    // fclose(stdin);
}

void solve(){
    ll res = 0;
    ll sum = 0; //luu tong hang 
    ll distance;
    ll a, b;// luu phan nguyen va phan du
    ll index = pos.size() - 1; 
    while (index >= 0){
        sum += pos[index].second;
        distance = pos[index].first;
        a = sum / k;
        b = sum % k;
        /*
            b > 0: con du hang tai vi tri index chua chuyen het
            b = 0: da chuyen het hang tai index
            b < 0: da chuyen het hang tai index truoc
        */

        if (b > 0){
            res += distance * 2 * (a + 1);
            sum = b - k;
        }
        else if (b == 0) {
            res += distance * 2 * a;
            sum = 0;
        }
        index--;
    }
    
    // tuong tu voi day negative
    ll len_neg = neg.size();
    index = 0;
    sum = 0;
    while (index < len_neg) {
        sum += neg[index].second;
        distance = -neg[index].first;
        a = sum / k;
        b = sum % k;

        if (b > 0){
            res += distance * 2 * (a + 1);
            sum = b - k;
        }
        else if (b == 0) {
            res += distance * 2 * a;
            sum = 0;
        }
        index++;
    }

    cout << res << endl;

}

int main(){
    input();
    solve();

    return 0;
}