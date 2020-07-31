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
int Num[10000] ;
vector<int> arr[1000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  N , K ;cin >> N >> K;
	for(int i=0; i<N;i++){
		cin >> Num[i];
	}
	for(int i=0; i<N;i++){
		if(i!=0){
			if(abs(Num[i]-arr[i].at(arr[i].size()-1))<=K)arr[i].pb(Num[i]);
		}else{
			arr[i].pb(Num[i]);
		}
	}
	int ask;cin >> ask;
	while(ask--){
		int q;cin >> q;
		ll fall = 0;
		for(auto x : arr){
			if(x.at(x.size()-1)){
				ll res = 0;
				for(auto v : x){
					res += v;
				}
				fall += res;
			}
		}
		cout << fall << endl;
	}
}
