#include<bits/stdc++.h>
using namespace std;
signed main(){
	set<int> s;
	multiset<int> ms;
	for (int i=0;i<5;i++){
		int tmp;cin >> tmp;
		s.insert(tmp);
		ms.insert(tmp);
	}
	
	for(auto &a : s){
		cout << a << " ";
	}
	cout << endl;
	cout << "UB 1: " << *s.upper_bound(1) << endl; 
	for(auto &a : ms)cout << a << " ";
}
