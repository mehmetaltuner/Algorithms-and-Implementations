#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define sc second
#define ALL(x) x.begin(), x.end()
#define RALL(X) x.begin(), x.end()
#define FOR(i, n, k) for(i=0; i<n; i+=k)
#define FO(i, n, k) for(i=1; i<=n; i+=k)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define N 100005
#define mid ((l+r)/2)
#define dbg(x) (cerr << #x << " : " << x << endl)
#define endl "\n"
#define MOD 100000009

using namespace std;

typedef long long int lli;

vector <vector <int>> adj(N, vector <int>());
vector <bool> visited(N, false);
vector <int> low(N, 0);
vector <int> idx(N, 0);
int cur_time, n, m;
stack <int> comp;
vector <bool> in_stack(N, 0);

void dfs(int n){
	low[n] = idx[n] = ++cur_time;
	comp.push(n);
	in_stack[n] = 1;

	for(int chi: adj[n]){
		if(!visited[chi]){
			visited[chi] = 1;
			dfs(chi);
			low[n] = min(low[n], low[chi]);
		}else if(in_stack[chi]){
			low[n] = min(low[n], idx[chi]);
		}
	}

	if(idx[n] == low[n]){
		cout << "NEW SCC BEGIN : " << endl;
		while(1){
			int x = comp.top(); comp.pop();
			in_stack[x] = 0;
			cout << x << " ";
			if(x == n) break;
		}	
		cout << endl << "SCC ENDS : " << endl << endl;
	}
}

void scc(){
	for(int i=1; i<=n; i++){
		if(!visited[i])
			dfs(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}

	scc();

	return 0;
}