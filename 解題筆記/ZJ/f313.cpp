#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int M[50+3][50+3];
int M2[50+3][50+3];

int R,C,k,m;
bool cango(int i,int j) {
	return M[i][j]!=-1 && i<R && i >=0 && j >=0 && j<C;
}
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int mm = 0x3f3f3f3f;
int MM = -1;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ms(M,0);
	ms(M2,0);
	cin >> R >> C >> k >> m;

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			int q;
			cin >> q;
			M[i][j]  = q;
			M2[i][j] = q;
		}
	}

	for(int _=0; _<m; _++) {

		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				int to_move = M[i][j]/k;
				int cnt =0;
				for(int x=0; x<4; x++) {
					if(cango(i+dx[x],j+dy[x]) && M[i][j] != -1) {
						//cout << ",To "<< i+dx[x] << " " << j+dy[x] << "; Step:" << to_move << endl;
						M2[i+dx[x]][j+dy[x]] += to_move;
						cnt++;
					}
				}
				M2[i][j] -= to_move*cnt;
				//cout << i << " " << j << "now: " << M2[i][j] << endl;
			}
		}
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				M[i][j] = M2[i][j];
			}
		}
	}


	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(M2[i][j]==-1)continue;
			mm = min(mm,M2[i][j]);
			MM = max(MM,M2[i][j]);
		}
	}
	cout << mm << endl << MM << endl;
	return 0;
}


