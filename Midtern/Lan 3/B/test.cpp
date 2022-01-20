#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define NMAX 505 
int n, k;
int x[NMAX], y[NMAX];
vector<bool> visit(NMAX, false);
struct edge{
	int u, v;
	int w;
	edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
	
};
vector<vector<edge> > Adj(NMAX);
void Enter(){
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>x[i]>>y[i];
	}
}
vector<int> Dijkstra(int start){
	vector<int> iDist(n+1, LONG_MAX);
	iDist[start] = 0;
	priority_queue <pair <int , int >,
	                vector <pair <int , int > >,
                    greater <pair <int , int > > > PQ;
    PQ.push(make_pair(iDist[start], start));
    while(!PQ.empty()){
    	int u = PQ.top().second;
    	PQ.pop();
    	for(edge e: Adj[u]){
    		int v = e.v;
    		int w = e.w;
    		if(iDist[v] > w + iDist[u]){
    			iDist[v] = w + iDist[u];
    			PQ.push(make_pair(iDist[v], v));
			}
		}
	}
	
	
	return iDist;
}
void Solve(){
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			int d = sqrt( (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i]-y[j]));
			if(d <= k){
				Adj[i].push_back(edge(i, j, d));
				Adj[j].push_back(edge(j, i, d));
			}
		}
	}
	vector<int> res = Dijkstra(1);
	if(res[n] < LONG_MAX) cout<<res[n];
	else cout<<-1;
}
main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Enter();
    Solve();
	
	
}