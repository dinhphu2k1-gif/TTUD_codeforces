#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
    edge (int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;

    }
};

int n, m, k;
vector <edge> listEdge;
int min_w = INT_MAX;
int par[35];
int mark[35]; //danh dau nhung canh nao dc chon
int res = INT_MAX;


bool compare(edge &a, edge &b){
    return a.w < b.w;
}

void input(){
    cin >> n >> m >> k;
    int u, v, w;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        listEdge.push_back(edge(u, v, w));

        min_w = min(min_w, w);
    }
    sort(listEdge.begin(), listEdge.end(), compare);

    // for (int i = 0; i < m; i++){
    //     cout << listEdge[i].u << " " <<  listEdge[i].v << " " << listEdge[i].w << " " << endl;
    // }
}

int Find(int x){
    if(par[x] == 0) return x;
    return par[x] =  Find(par[x]);
}
void Union(int x, int y){
    par[x] = y;
}

void solve(int t, int num, int weight){
    // cout << t << " " << num  << " " << weight << endl;
    if (num == k){
        for (int i = 1; i <= n; i++){
            par[i] = 0;
        }

        for (int i = 0; i < m; i++){
            if (mark[i] == false) continue;

            int x = listEdge[i].u;
            int y = listEdge[i].v;

            x = Find(x);
            y = Find(y);

            if(x == y) return;
            Union(x,y);
        }

        res = min(res, weight);
        // cout << res << endl;
        return;
    }

    if (t >= m) return;
    if (weight + (k - t) * min_w > res) return;

    mark[t] = true;
    solve(t + 1, num + 1, weight + listEdge[t].w);
    mark[t] = false;
    solve(t + 1, num, weight);
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);

    solve(0, 0, 0);
    cout << res;

    return 0;
}