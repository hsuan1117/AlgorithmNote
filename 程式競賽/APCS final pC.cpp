#include<bits/stdc++.h>
#include<map>
#define endl '\n'
#define psi pair<string,int>
using namespace std;

map<string ,int> L;
vector<psi> x;
bool cmp(psi,psi);
int main() {
	string name;
	while(getline(cin,name) && name != "***"){
		if(L[name]){
			L[name]++;
		}else{
			L[name] = 1;
		}
	}
	
	for(psi a:L){
		x.emplace_back(a);
	}
	
	sort(x.begin(),x.end(),cmp);
	
	if(x[0].second == x[1].second){
		cout << "Runoff!" << endl;
	}else{
		cout << x[0].first << endl;
	}
	
	return 0;
}

bool cmp(psi a,psi b){
	return a.second > b.second;
}
