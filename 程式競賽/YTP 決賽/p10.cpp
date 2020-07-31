#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
struct str{
	ll a,b,m;
}arr[500005];
ll N,dp[500005];
bool cmp(str x,str y){
	return x.b<y.b;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>N;
	for(ll i=1;i<=N;i++)cin>>arr[i].a>>arr[i].b>>arr[i].m;
	sort(arr+1,arr+N+1,cmp);
	ll t=1;
	for(ll i=1;i<=arr[N].b;i++){
		dp[i]=dp[i-1];
		while(arr[t].b==i){
			dp[i]=max(dp[i],dp[arr[t].a]+arr[t].m);
			t++;
		}
	}
	cout<<dp[arr[N].b]<<'\n';
}
