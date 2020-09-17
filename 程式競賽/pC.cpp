#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define pb emplace_back

using namespace std;
vector<vi> E(1000);
int killed = -1;
int bfs(int x) {
	int n=0;
	queue<int> q;
	vi vis(1000,0);
	q.emplace(x);
	while(!q.empty()) {
		int u = q.front();

		//cout << "    VIS: " << u << endl;

		if(vis[u] || u == killed) {
			q.pop();
			continue;
		} else {
			vis[u] = 1;
			//cout << "    ++" << endl;
			n++;
		}
		q.pop();
		for(auto e:E[u])q.emplace(e);
	}

	return n;
}

signed main() {
	ios
	int N;
	cin >> N;
	// E[start] = [end1, end2 ]
	//for(int i=1;i<=N;i++)E[i].pb(i);
	rep(i,N-1) {
		int a,b;
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}
	int M;
	cin >> M >> killed;
	/*
	cout <<"E : " << endl;
	for(int i=0;i<N;i++){
		cout << " " << i << endl << "  ";
		for(int e:E[i]){
			cout << " " << e ;
		}
		cout << endl;
	}*/
	E[killed].clear();
	int all = 0;
	for(int k=1; k<=N; k++) {
		//cout << "Start BFS " << k << endl;
		for(auto e : E[k]) {
			int nn = bfs(e);
			//cout << "  BFS: " << nn << endl;
			all += nn;
		}
	}

	cout << all << endl;


	return 0;
}
/*
5
1 2
2 3
3 4
4 5
1
3
*/

