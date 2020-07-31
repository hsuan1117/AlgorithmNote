#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll N,dp[10],num[105],sum[105],arr[10],t=0;
bool vis[105];
string S;
ll dfs(ll n){
	if(n==0){
		return 1;
	}
	ll ans=0;
	for(ll i=0;i<t;i++){
		if(num[arr[i]]<sum[arr[i]]&&arr[i]!=dp[n]){
			num[arr[i]]++,dp[n-1]=arr[i];
			ans+=dfs(n-1);
			num[arr[i]]--,dp[n-1]=0;
		}
	}
  return ans;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>S;
	for(ll i=0;i<N;i++){
		if(!vis[(int)S[i]])vis[(int)S[i]]=1,arr[t++]=(int)S[i];
		sum[(int)S[i]]++;
	}
  cout<<dfs(N)<<'\n';
}
