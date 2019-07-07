#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define sc second
#define ALL(x) x.begin(), x.end()
#define RALL(X) x.begin(), x.end()
#define FOR(n) for(int i=0; i<n; i++)
#define FO(n) for(int i=1; i<=n; i++)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define N 1005
#define n N
#define mid ((l+r)/2)
#define dbg(x) (cerr << #x << " : " << x << endl)
#define MOD 1000000009
 
using namespace std;
 
typedef long long int lli;
 
vector <vector <int>> adj(N, vector <int>());
vector <vector <int>> cap(N, vector <int>(N, 0));
 
int bfs(int s, int t, vector <int> &parent){
	queue <pii> q;
	q.push({s, INT_MAX/2});
	fill(ALL(parent), -1);
	parent[s] = -2;
 
	while(!q.empty()){
		int node = q.front().fi;
		int flow = q.front().sc;
		q.pop();
 
		for(int chi: adj[node]){
			if(parent[chi] == -1 and cap[node][chi] != 0){
				parent[chi] = node;
				flow = min(flow, cap[node][chi]);
				if(chi == t)
					return flow;
				q.push({chi, flow});
			}
		}
	}
	return 0;
}
 
int sz, m;
 
int maxflow(int s, int t){
	vector <int> parent(n, -1);
	int max_flow = 0;
	int flow;
	while((flow = bfs(s, t, parent))){
		max_flow += flow;
		for(int i=t; i!=s; ){
			cap[parent[i]][i] -= flow;
			cap[i][parent[i]] += flow;
			i = parent[i];
		}
	}
	return max_flow;
}
 
signed main(){
	ios_base::sync_with_stdio(false);

	cin >> sz >> m;
 
	for(int i=0 ;i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].pb(b);
		adj[b].pb(a);
		cap[a][b] = c;
	}
 
	cout << maxflow(1, sz);
	return 0;
}