#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>

using namespace std;

int N,M;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int MM[100][100];
long long mm = INF;
long long total = 0;
pair<int , int > p;
map<pair<int , int >, bool> vis;
bool cango(int x,int y) {
	#ifdef DEBUG
	cout << "Check " << x << " " << y << endl;
	if(x>=0&&y>=0&&x<N&&y<M&&!vis[make_pair(x,y)])cout << "ok!" << endl;
	#endif
	
	return x>=0&&y>=0&&x<N&&y<M&&!vis[make_pair(x,y)];
}
void dfs(int x,int y) {
	#ifdef DEBUG
	cout << "Went  " << x << " " << y << endl;
	#endif

	vis[make_pair(x,y)] = 1;
	total += MM[x][y];
	int to_x=-1,to_y=-1,mini=INF;
	for(int k=0; k<4; k++) {
		if(cango(x+dx[k],y+dy[k])) {
			int mini2 = min(mini,MM[x+dx[k]][y+dy[k]]);
			if(mini2 != mini) {
				#ifdef DEBUG
				cout << x+dx[k] << "," << y+dy[k] << " is " << MM[x+dx[k]][y+dy[k]] << endl;
				#endif
				 
				to_x = x+dx[k];
				to_y = y+dy[k];
				mini = mini2;
			}

		}
	}
	if(to_x != -1 && to_y != -1) {
		#ifdef DEBUG
		cout <<"GoTo " << to_x << " " << to_y << endl;
		#endif
		
		dfs(to_x,to_y);
	}

}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ms(MM,0);
	cin >> N >> M ;
	long long m2 = INF;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> MM[i][j];
			m2 = min(mm,MM[i][j]);
			if(mm != m2) {
				p = make_pair(i,j);
				mm = m2;
			}
		}
	}
	dfs(p.first,p.second);
	cout << total << endl;

	return 0;
}


