#include <bits/stdc++.h>

using namespace std;

int n;
int matrix[30][30];
int place[30];
int minRoute = INT_MAX, cmin = INT_MAX;
int route = 0;
int pas = 0;
int r;

void input(){
    cin >> n;
    r = 2*n;
    for (int i = 0; i <= r; i++){
        for (int j = 0; j <= r; j++){
            cin >> matrix[i][j];
            if (i != j) cmin = min(cmin, matrix[i][j]);
        }
    }
}

void solve(int k){
    if (r == 0){
        minRoute = min(minRoute, route + matrix[k][0]);
        return ;
    }

    if (pas == 0){
        for (int i = 1; i <= n; i++){
            if (place[i] == 0){
                route += matrix[k][i];
                place[i] = 1;
                pas = 1;
                r--;

                if (route + r * cmin < minRoute) solve(i);
                route -= matrix[k][i];
                place[i] = 0;
                pas = 0;
                r++;
            }
        }
    }

    for (int i = n + 1; i <= 2 * n; i++){
        if (place[i] == 0 && place[i - n] == 1){
            route += matrix[k][i];
            place[i] = 1;
            pas = 0;
            r--;

            if (route + r * cmin < minRoute) solve(i);
            route -= matrix[k][i];
            place[i] = 0;
            pas = 1;
            r++;

        }
    }
}




int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve(0);
    cout << minRoute;

    return 0;
}