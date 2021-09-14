#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int M[100][100];
int total =0 ;
int _x, _y;
int mm = 0x3f3f3f3f;
int vis[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool cango(int x, int y){
	return 0 <= x and x < m and 0 <= y and y < n and !vis[x][y];
}
void dfs(int x, int y){ //cout << x << " , " << y << " => " << M[x][y] << endl;
	total += M[x][y];
	vis[x][y] = true;
	int _i = -1, _j = -1;
	int mmm = 0x3f3f3f3f;
	for(int i=0;i<4;i++){
		//cout << "     in <dfs>for " << x+dx[i] << " , " << y+dy[i] ;
		//system("sleep 2");
		//cout << " => " << M[x+dx[i]][y+dy[i]];
		if(cango(x+dx[i], y+dy[i])){
			//cout << " now " << mmm << endl;
			if(M[x+dx[i]][y+dy[i]] < mmm){
				_i = x+dx[i];
				_j = y+dy[i];
				mmm = M[_i][_j];
			}		
		}
	}
	//cout << " <dfs > " << _i << " , " << _j << endl; 
	if(_i == -1 and _j == -1)return;
	dfs(_i, _j);
}

signed main(){
	cin >> m >> n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> M[i][j];
			if(M[i][j] < mm){
				mm = M[i][j];
				_x = i;
				_y = j;
			}
		}
	}
	//cout << " <main> " << _x << " , " << _y << endl;
	dfs(_x, _y);
	cout << total << endl;
	return 0;
}
