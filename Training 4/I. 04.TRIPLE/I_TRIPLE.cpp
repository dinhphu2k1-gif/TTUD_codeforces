#include <bits/stdc++.h>

using namespace std;

int N, K;
vector <int> a;
int cnt = 0;

void input(){
    cin >> N >> K;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
}

void solve(int left, int right, int k){
    // cout << left << " " << right << endl;
    if (left > right) return;

    int mid = (left + right) / 2;

    if (a[mid] == k){
        cnt++;
        // cout << k << endl;
        solve(left, mid - 1, k);
        solve(mid + 1, right, k);
    }
    else if (a[mid] > k){
        solve(left, mid - 1, k);
    }
    else {
        solve(mid + 1, right, k);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    for (int i = 0; i < N - 2; i++){
        for (int j = N - 1; j >= i + 2; j-- ){
            if (K - a[i] - a[j] <= 0) continue;
            // cout << i << " " << j << " " << K - a[i] -a[j] << endl;
            solve(i + 1, j - 1, K - a[i] -a[j]);
        }
    }
    cout << cnt;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// const int MAX = 100005;
// int n, K, cnt;
// int a[MAX];

// void inputData(){
//     cnt = 0;
//     cin >> n >> K;
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
// }

// int bsearch(int first, int last, int key){
//     if(first <= last){
//         int mid = first + (last - first) / 2;
//         if(a[mid] == key){
//             cout << key << endl;
//             return 1 + bsearch(first,mid-1,key) + bsearch(mid+1,last,key);
//         } 
//         else {
//             if(a[mid] > key) return bsearch(first, mid-1, key);
//             else return bsearch(mid+1, last, key);
//         }
//     }
//     return 0;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     freopen("input.txt", "r", stdin);
//     inputData();
//     fclose(stdin);
//     sort(a,a+n);

//     for(int i=0; i<n-2; i++)
//         for(int j=i+1; j<n-1; j++){
//             cout << i << " " << j << " " << K - a[i] -a[j] << endl;
//             if(K-a[i]-a[j] <= 0) continue;
//             int k = bsearch(j+1, n-1, K-a[i]-a[j]);
//             cnt += k;
//         }
//     cout << cnt;
//     return 0;
// }