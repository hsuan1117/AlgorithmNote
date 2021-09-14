#include<bits/stdc++.h>

using namespace std;
int N,M,S;

int height[100000];

int cnt1 =0;
int cnt2 =0;

bool vis[100000];
vector<int> v1[10000];
vector<int> v2[10000];
long long m = 0x3f3f3f3f;
bool cango1(int t, int f){
	// target, from
	return !vis[t] && height[t] != m;	
}

bool cango2(int t,int f){
	return !vis[t] && height[t] != m;
}

void go1(int t,int f){
	cout << "vis1 " << t << " (" << height[t] << ")" << endl;
	cnt1++;
	vis[t] =1;
	for(auto &x : v1[t]){
		if(cango1(x, t)){
			go1(x, t);
		}
	}
	return;
}

int go2(int t,int f){
	cout << "vis2 " << t << " (" << height[t] << ")" << endl;
	cnt2++;
	vis[t] = 1;
	for(auto &x : v2[t]){
		if(cango2(x, t))go2(x, t);
	}
}


signed main(){
	int T;cin >> T;

	for(int _ =1;_<=T;_++){
		// case _
		cin >> N >> M >> S;

		for(auto &x:v1)x.clear();
		for(auto &x:v2)x.clear();		

		// min
		m = 0x3f3f3f3f;
		
		for(int i=0;i<N;i++){
			long long tmp;cin >> tmp;
			height[i] = tmp;
			m = min(tmp, m);
		}	
		
		for(int i=0;i<M;i++){
			int a,b;cin >> a >> b;
			int _a = height[a], _b = height[b];
			if(_a<_b){
				v1[b].emplace_back(a);
			} else {
				v1[a].emplace_back(b);
			}
			v2[a].emplace_back(b);
			v2[b].emplace_back(a);
		}	
		memset(vis, 0, sizeof(vis));
		go1(S, -1);		
		long long xa = 1 * cnt1;
		memset(vis, 0, sizeof(vis));
		go2(S, -1);
		long long xb = 6 * cnt2;
		cout << "total1: " << cnt1 << endl;
		cout << "total2: " << cnt2 << endl;
		cout << "Case #" << _ << ": " << abs(xa-xb) << endl; 
	}

	return 0;
}
