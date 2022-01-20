/***** TESTING INPUT *****
7 11
1 4 5
4 6 6
4 5 15
2 3 8
3 5 5
5 7 9
6 7 11
4 2 9
2 5 7
1 2 7
6 5 8
1
***** OUTPUT *****
1 -> 1 : 0
1 -> 2 : 7
1 -> 3 : 15
1 -> 4 : 5
1 -> 5 : 14
1 -> 6 : 11
1 -> 7 : 22
*****************/
#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
struct edge
{
    int u;      // vertex 1
    int v;      // vertex 2
    int weight; // weight

    edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};
vector<edge> Adj[100];
vector<int> iDist(100, INF);
void Dijkstra(int start)
{
    iDist[start] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        PQ;
    PQ.push(make_pair(iDist[start], start));
    while (!PQ.empty())
    {
        int u = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].v;
            int w = Adj[u][i].weight;
            if (w + iDist[u] < iDist[v])
            {
                iDist[v] = w + iDist[u];
                PQ.push(make_pair(iDist[v], v));
            }
        }
    }
}
int main(){
    // input
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2 [] weight
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
    }
    // preprocess : Adj = vector<edge>[] which represents edge from vertex v
    for(edge e : edges){
        Adj[e.u].push_back({e.u, e.v, e.weight});
        Adj[e.v].push_back({e.v, e.u, e.weight});
    }
    int start;
    cin >> start;
    Dijkstra(start);
    for(int i = 1; i <= n; i++){
        cout << start << " -> " << i << " : " << iDist[i] << endl;
    }
}