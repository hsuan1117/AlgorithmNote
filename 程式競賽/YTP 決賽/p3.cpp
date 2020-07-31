#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll dp[2000000];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll K;cin >> K;
	for(int i=1; i<2000000; i++){
		dp[i] += dp[i-1] + i ;
	}
	cout << upper_bound(dp,dp+2000000,K) - dp -1 << endl;
}
