#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define rep(i,n) for(ll i=0;i<(long long)(n);i++)
#define pb emplace_back
using namespace std;

signed main() {
	ios
	ll n;cin >> n;
	long long all = 0;
	rep(i,n){
		ll x;cin >> x;
		all += x;
	}
	//cout << all << endl;
	ll k;cin >> k;
	rep(n,k){
		ll l,r,w;cin >> l >> r >> w;
		all += (r-l+1)*w;
		cout << all << endl;
	}
	return 0;
}

/*
5
1 2 3 4 5
2
2 4 1
3 4 10


*/
