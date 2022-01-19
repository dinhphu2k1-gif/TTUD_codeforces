#include <bits/stdc++.h>

using namespace std;
#
int N, M;
vector <int> arr;
int Hmin = 1e9, Hmax = 0;
int res = 0;

void input(){
    cin >> N >> M;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        arr.push_back(tmp);
        Hmin = min(Hmin, tmp);
        Hmax = max(Hmax, tmp);
    }
}

void solve(int left, int right){
    int mid = (right + left) / 2;

    long long sum = 0;
    for (int i = 0; i < N; i++){
        if (arr[i] > mid) sum += arr[i] - mid;
    }

    if (left == mid) return ;
    else {
        if (sum >= M){
            res = mid;
            solve(mid, right);
        } 
        else solve(left, mid);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve(Hmin, Hmax);
    cout << res;

    return 0;
}