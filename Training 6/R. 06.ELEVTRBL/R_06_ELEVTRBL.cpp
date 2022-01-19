#include <bits/stdc++.h>

using namespace std;
int f, s, g, u, d;

vector <int> visited;
bool success = false;
int cnt = 0;

void input(){
    cin >> f >> s >> g >> u >> d;
    visited.resize(f + 1);
}
bool solve(int index){
    cnt ++;
    if (visited[index] == true ) return false;
    if (index == g) return true;

    if (index < g) {
        if (index + u <= f) return solve(index + u);
        else if (index - d >= 1) return solve(index - d);
        else return false;
    }
    else {
        if (index - d >= 1) return solve(index - d);
        else  if (index + u <= f) return solve(index + u);
        else return false;
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    if (s == g){
        cout << 0;
    }
    else {
        if (solve(s)) cout << cnt - 1;
        else cout << "use the stairs";
    }
    // solve(s);
    return 0;
}