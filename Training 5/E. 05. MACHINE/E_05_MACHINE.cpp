//C1

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<pair<ll, ll>> arr;
map<ll, ll> maxDis;
ll max_cur = 0;
ll res = 0;
int mark = 0;

void input()
{
    cin >> n;
    ll s, t;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        arr.push_back({s, t});
    }

    sort(arr.begin(), arr.end());
    // for (int i = 0; i < n; i++){
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
}

void solve()
{
    map<ll, ll>::iterator it;
    ll x, y;

    max_cur = arr[0].second - arr[0].first;
    maxDis[arr[0].second] = max_cur;

    for (int i = 1; i < n; i++)
    {   
        x = arr[i].first;
        y = arr[i].second;
        if (y - x + max_cur <= res ) continue;
        max_cur = max(max_cur, y - x);

        it = maxDis.end();
        it--;
        //xet gia tri lon nhat tai vi tri end
        if (y > it->first)
        {
            maxDis[y] = max(y - x, it->second);
        }

        while (it != maxDis.begin())
        {
            if (x > it->first){
                break;
            }
            it--;
        }
        if (it->first < x){
            mark = 1;
            res = max(res, it->second + y - x);
        }
        // cout << res << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve();

    if (mark == 1) cout << res;
    else cout << -1;

    return 0;
}


//C2
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// typedef struct machine{
//     int start;
//     int end;
//     int value;
// }machine;
// bool sortt(machine a, machine b){
//     if(a.start == b.start){
//         return a.end < b.end;
//     }
//     else{
//         return a.start < b.start;
//     }
// }
// machine A[2000100];
// int res = -1;
// int max_cur_value = -1;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> A[i].start >> A[i].end;
//         A[i].value = A[i].end - A[i].start;
//     }
//     sort(A+1, A+n+1, sortt);
//     //F[i] la gia tri lon nhat thu duoc co A[i] la phan tu cuoi cung;
//     for(int i = 1; i <= n; i++){
//         if(A[i].end - A[i].start + max_cur_value >= res)
//         for(int j = 1; j < i; j++){
//             if(A[j].end < A[i].start ){
//                 res = max(res, A[i].end+A[j].end - A[i].start - A[j].start);
//             }
//         }
//         max_cur_value = max(max_cur_value, A[i].end - A[i].start);
//     }
//     cout << res;
// }