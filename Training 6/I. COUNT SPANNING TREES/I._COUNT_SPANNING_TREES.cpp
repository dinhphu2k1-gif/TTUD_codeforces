// #include <bits/stdc++.h>

// using namespace std;
// int n, m;
// vector <vector <int>> edge;
// int parent[30];
// bool mark[30]; //danh dau canh nao da duoc lay
// int cnt = 0;

// void input(){
//     cin >> n >> m;

//     edge.resize(m + 1);
//     int tmp1, tmp2;
//     for (int i = 1; i <= m; i++){
//         cin >> tmp1 >> tmp2;
//         edge[i].push_back(tmp1);
//         edge[i].push_back(tmp2);
//         mark[i] = false;
//     }

//     sort(edge.begin(), edge.end());

//     // for (int i = 1; i <= m; i++){
//     //     cout << edge[i][0] << " " << edge[i][1] << endl;
//     // }
// }

// int Find(int x){
//     if (parent[x] == 0) return x;
//     while (parent[x] != x){
//         x = parent[x];
//     }
//     return parent[x];
// }

// void Union(int x, int y){
//     if (x < y) parent[y] = parent[x];
//     else parent[x] = parent[y];
// }

// void solve(int t, int num){

    
//     if (num ==  n - 1){
//         // cout << t << " " << num << endl;
//         for (int i = 0; i <= n; i++){
//             parent[i] = 0;
//         }

//         for (int i = 1; i <= m; i++){
//             if (!mark[i]) continue;

//             int x = edge[i][0];
//             int y = edge[i][1];

//             parent[x] = Find(x);
//             parent[y] = Find(y);

//             if (parent[x] == parent[y] ) return ;
//             else Union(x, y);
//         }

//         // for (int i = 1; i <= m; i++){
//         //     if (!mark[i]) continue;

//         //     cout << i << " ";
//         // }
//         // cout << endl;
//         cnt++;
//         return;
//     }

//     if (t > m) return ;

//     mark[t] = true;
//     solve(t + 1, num + 1);
//     mark[t] = false;
//     solve(t + 1, num);
// }   

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     // freopen("input.txt", "r", stdin);
//     input();
//     // fclose(stdin);

//     solve(1, 0);
//     cout << cnt;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n, m, res;
int edge[32][32];
int par[32];
bool c[32];
int Find(int x){
    if(par[x] <0) return x;
    return par[x] =  Find(par[x]);
}
void Union(int x, int y){
    par[x] = y;
}
void attempt(int t, int num){
    if(num == n-1){
        for(int i = 1; i <= n; i++){
            par[i] = -1;
        }
        for(int i = 1; i <=m ; i++){
            if(c[i] == false) continue;
            int x = edge[i][0];
            int y = edge[i][1];

            x = Find(x);
            y = Find(y);

            if(x==y) return;
            Union(x,y);
        }
        res++;
        return;
    }
    if(t>m) return;
    c[t] = true;
    attempt(t+1,num+1);
    c[t] = false;
    attempt(t+1,num);
}
int main(){
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        cin>>edge[i][0]>>edge[i][1];
    }
    res =0;
    attempt(1,0);
    cout<<res;
}