#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> listP;
bool visited[505];
bool res = false;
int dis[505];
int INF = INT_MAX;

struct edge
{
    int u, v;
    int w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    };
};

vector<edge> Adj[505];

int cal_distance(pair<int, int> x, pair<int, int> y)
{
    return floor(sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2)));
}

void input()
{
    cin >> n >> k;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        listP.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dis = cal_distance(listP[i], listP[j]);
            if (dis <= k)
            {
                Adj[i].push_back(edge(i, j, dis));
                Adj[j].push_back(edge(j, i, dis));
            }
        }
    }
    // cout << Adj[0][0].v;
}

void Dijkstra(int start)
{
    vector<int> iDist(n + 1, INF);
    iDist[start] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        PQ;
    PQ.push(make_pair(iDist[start], start));
    // cout << "ok";
    while (!PQ.empty())
    {
        int u = PQ.top().second;
        // cout << u << endl;
        PQ.pop();
        for (edge e : Adj[u])
        {
            int v = e.v;
            int w = e.w;
            if (iDist[v] > w + iDist[u])
            {
                iDist[v] = w + iDist[u];
                PQ.push(make_pair(iDist[v], v));
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << iDist[i] << " ";
    // }

    // cout << endl;
    if (iDist[n - 1] != INF)
        cout << iDist[n - 1];
    else
        cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    Dijkstra(0);

    return 0;
}
