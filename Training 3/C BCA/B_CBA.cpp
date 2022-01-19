#include <bits/stdc++.h>

using namespace std;

int m, n;
int course[15][35];
map <pair <int, int>, int> ls_conflict;
vector <vector <int>> teacher; // luu cac khoa hoc da dc gan cho giao vien
int load[15]; // load cua cac giao vien
int maxLoad = 0;
int minOfAllTeacher = 2147483647;


void input(){

    cin >> m >> n;
    int k, tmp;
    teacher.resize(m + 1);
    for (int i = 1; i <= m; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> tmp;
            course[i][tmp] = 1;
        }
    }

    cin >> k;
    int x, y;
    for (int i = 0; i < k; i++){
        cin >> x >> y;
        ls_conflict[{x, y}] = 1;
        ls_conflict[{y, x}] = 1;
    }
}

bool check(int k, int i){ // khoa hoc k duoc gan cho thay giao i
    if (course[i][k] == 0) return false; 
    
    int c;
    for (int j = 0; j < teacher[i].size(); j++){
        c = teacher[i][j];
        if (ls_conflict[{c, k}] == 1) return false;  
    }
    return true;
}

void solve(int k){
    for (int i = 1; i <= m; i++){
        if (check (k, i)){
            teacher[i].push_back(k);
            load[i] += 1;
            int pre = maxLoad;
            maxLoad = max(maxLoad, load[i]);
            // cout << k << " " << i << endl;
            if (k == n){
                minOfAllTeacher = min(minOfAllTeacher, maxLoad);
            } 
            else {
                if (maxLoad < minOfAllTeacher) solve(k + 1);
            }

            teacher[i].pop_back();
            load[i] -= 1;
            maxLoad = pre;
        }

    }

}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    solve(1);
    if (minOfAllTeacher != 2147483647) cout << minOfAllTeacher;
    else cout << -1;

    return 0;
}