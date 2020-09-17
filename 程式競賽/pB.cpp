#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define pb emplace_back

using namespace std;
signed main() {
	ios
	long long N,K,M;cin >> N >> K >> M ;
	long long mm = -1;
	rep(i,N){
		long long x;cin >> x;
		if(K%x != 0){
			mm = max((K/x)+1,mm);
		}else{
			mm = max(K/x,mm);
		}
		
	}
	
	if(mm<=0){
		cout << 1  << endl;
	}else{
		cout << mm << endl;
	}
	return 0;
}


