#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N;cin >> N;
	int all = 0;
	while(N--){
		int tmp;cin >> tmp;
		all += tmp;
	}
	int X;cin >> X;
	while(X--){
		int L,R,M;cin >> L >> R >> M;
		cout << (all+=(R-L+1)*M) << endl;
	}

	return 0;
}
