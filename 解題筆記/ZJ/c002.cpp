#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f
#define pb emplace_back
#define ull unsigned long long
#define pll pair<ll,ll>
using namespace std;

ull f91(ull N){
	if(N<=100){
		return f91(f91(N+11)); 
	}else{
		return N-10;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ull N;
	while(cin>>N&&N!=0){
		cout << "f91(" << N << ") = "<< f91(N) << endl; 
	}
	return 0;
}


