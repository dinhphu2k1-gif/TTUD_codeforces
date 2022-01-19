#include <bits/stdc++.h>

using namespace std;

int N, M;
int c[20]; 
vector <vector <int>> before;
int after[20];
int cond[20]; // save all of the course after
int periods[10];
int minAllPeriods = INT_MAX;
int maxLoad = 0;

void input(){
    cin >> N >> M;
    before.resize(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> c[i];
    }
    int tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++){
            cin >> tmp;
            if (tmp){
                before[i].push_back(j);
                cond[j] = 1;
            }
        }
    }
}

bool check(int k, int i){
    if (cond[k]) return true;

    // The semester of the prerequisite subject must be smaller than the following subject
    for (int j : before[k]){
        if (i < after[j]) return false;
    }
    return true;
}

void TRY(int k){
    //course k th will be assigned to i th periods
    for (int i = 1; i <= M; i++){
        if (check(k, i)){
            periods[i] += c[k];
            after[k] = i;
            int pre = maxLoad;
            maxLoad = max(maxLoad, periods[i]);

            if (k == N){
                minAllPeriods = min(minAllPeriods, maxLoad);
            }
            else {
                if (maxLoad < minAllPeriods) TRY(k + 1);
            }

            periods[i] -= c[k];
            after[k] = 0;
            maxLoad = pre;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    TRY(1);
    cout << minAllPeriods;

    return 0;
}