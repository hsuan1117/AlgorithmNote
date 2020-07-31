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
ll N,Q,D[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
  for(ll i=0,a,b,c;i<N;i++){
		cin>>a>>b>>c;
		arr[a].push_back({c,b});
	}
	for(ll i=0,s,t;i<Q;i++){
		cin>>s>>t;
		cout<<D[s]
	}
}
