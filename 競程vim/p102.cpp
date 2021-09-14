#include<bits/stdc++.h>
#define int long long 
using namespace std;

int road[100][100];
int n;
struct Vis {
	vector<int> v;
	int total = 0;
}

bool cango(int x){
	return x < n && x >=0;
}

Vis dfs(Vis v,int f,int t){
	if(find(v.v.begin(),v.v.end(), t)==v.end()){
		//走過
		return v;
	} else {
		v.v.push(t);
		v.total += road[f][t];
		
		set<Vis> x;
		if(cango(t+1))x.push(dfs(v, t, t+1));
		if(cango(t-1))x.push(dfs(v, t, t-1));
		return v;
	}
	return dfs()
}

signed main(){
	in >> n;
	
	for(int i=0;i<n-1;i++){
		int _,__,w;
		cin >> _ >> __ >> w;
		road[_][__] = road[__][_] = w;
	}			
	
	set<vector<int>> a;

	for(int i=0;i<n;i++){
		// start: i
		Vis v;
		a.push(dfs(v).v, -1, i);				
	}

	cout << (*a.begin()).size() << endl;	


	return 0;
}
