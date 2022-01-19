#include <bits/stdc++.h>

using namespace std;

int n, b;
vector <pair<int, int>> ls;
int mark[35];
int cost_max = 0;
int weight = 0;
int cost = 0;

void input(){
    // freopen("input.txt", "r", stdin);
    cin >> n >> b;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        ls.push_back({x, y});
    }
    // fclose(stdin);
}


void solve(int k){
    for (int i = k; i < n; i++){
        if (mark[i] == 0){
            int a, c;
            a = ls[i].first;
            c = ls[i].second;
            mark[i] = 1;
            weight += a;
            cost += c;

            if (weight > b) cost_max = max(cost_max, cost - c);
            else {
                cost_max = max(cost_max, cost);
                solve(i + 1);
            }

            mark[i] = 0;
            weight -= a;
            cost -= c;
        }
    }
}

int main(){
    input();
    solve(0);

    cout << cost_max;
    return 0;
}