#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
	vector<pair<int, int>> brown;
        for(int i=0;i<3;i++){
		int a,b,c;cin >> a >> b >> c;
		pair<int, int> x;
 		x = {a, i};
		brown.emplace_back(x);
	}	
	sort(brown.begin(), brown.end());
	for(auto x: brown)cout << x.first << " " << x.second << endl;
	return 0;
}
