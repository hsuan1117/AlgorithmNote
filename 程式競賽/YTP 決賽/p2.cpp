#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll k[100005],d[100005],n,m,t;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>t;
	for(ll i=0;i<n;i++)cin>>k[i];
	for(ll i=0;i<t;i++)cin>>d[i];
	ll now=0,melt=0,ti=0,round=0;
	while(now<=n-1){
		round++;
		now+=d[ti++];
		now+=k[now];
		if(now>=n-1)break;
		melt+=m;
		n-=m;
		if(now<melt)break;
	}
	if(now==n-1)cout<<"Winner Penguin\n";
	else cout<<"Dumb Dumb Penguin\n";
	cout<<"Survived "<<round<<" rounds\n";
}
