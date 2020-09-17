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
	int N;cin >> N;
	vi num(N);
	rep(i,N){
		cin >> num[i];
	}
	cout << endl;
	vector<string> all;
	sort(num.begin(),num.end());
	do {
		string x,y;
        rep(i,N){
        	x+=(char)(num[i]+'0');
		}
		y = x;
		reverse(x.begin(),x.end());
		
		//cout << x <<  endl<< y <<  endl<< endl;
		if(x==y){
			
			all.pb(x);
		}
    } while(std::next_permutation(num.begin(), num.end()));
	for(auto xx : all ){
		cout << xx;
		cout << endl;
	}
	
	return 0;
}


