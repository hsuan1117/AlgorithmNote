#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
vector<pll> arr[500005];
set<pll> s;
bool vis[500005];
const ll Max=1e16;
ll N,M,K,D[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	for(ll i=2;i<=N;i++)D[i]=Max;
  for(ll i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		arr[a].push_back({c,b});
	}

	s.insert({0,1});
	while(!s.empty()){
		pll x=*s.begin();
		s.erase(x);
		for(auto i:arr[x.se]){
			D[i.se]=min(D[i.se],D[x.se]+i.fi);
			if(!vis[i.se])vis[i.se]=1,s.insert(i);
		}
		vis[x.se]=0;
	}
	for(ll i=1;i<=N;i++)cout<<D[i]<<" ";
	cout<<'\n';
}
