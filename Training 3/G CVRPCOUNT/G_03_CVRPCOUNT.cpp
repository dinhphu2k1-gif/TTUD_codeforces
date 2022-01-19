#include <bits/stdc++.h>

using namespace std;

int n, K, Q;
int d[20];
int factorial[20];
int capacity[20], route[20];
int place[20];
int res = 0;

void input(){
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
    }

    int tmp = 1;
    for (int i = 1; i <= n; i++){
        tmp *= i;
        factorial[i] = tmp;
    }
}

bool check(int t, int i){
    if (place[t]) return false;
    if (capacity[i] + d[t] > Q) return false;

    return true;
}

int add(){
    int tmp = 1;
    for (int i = 1; i <= K; i++){
        tmp *= factorial[route[i]];
        // cout << route[i] << " ";
    }
    return tmp;
}

// the t th position is assigned to the i th route
void solve(int t){
    for (int i = 1; i <= K; i++){  
        if (check(t, i)) {
            route[i]++;
            capacity[i] += d[t];
            place[t] = 1;

            if (t == n){
                res += add();
                // cout << res << endl;
            }
            else solve(t + 1);

            route[i]--;
            capacity[i] -= d[t];
            place[t] = 0;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve(1);
    cout << res/factorial[K];

    return 0;
}