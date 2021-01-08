#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<string> L;
vector<string> modify(int line,string s);
pair<int ,int> run(vector<string> a);
int main() {
	int dX,dY;
	cin >> dX >> dY;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string x;
		cin >> x;
		L.push_back(x);
	}
	
	for(int i=0;i<n;i++){
		pair<int,int > xx;
		xx = run(modify(i,"Right"));
		if(xx.first==dX&&xx.second==dY){
			cout << i+1 << " Right" << endl;
			return 0;
		}
		
		xx = run(modify(i,"Left"));
		if(xx.first==dX&&xx.second==dY){
			cout << i+1 << " Left" << endl;
			return 0;
		}
		
		xx = run(modify(i,"Forward"));
		if(xx.first==dX&&xx.second==dY){
			cout << i+1 << " Forward" << endl;
			return 0;
		}
	}

	return 0;
}

vector<string> modify(int line,string s){
	vector<string> a;
	a = L;
	a[line] = s;
	return a;	
}

pair<int ,int> run(vector<string> a){
	int z=1;
	int x=0,y=0;
	//  1
	// 4 2
	//  3
	for(string m : a){
		if(m=="Right"){
			z=(z==4?1:z+1);	
		}else if(m=="Left"){
			z=(z==1?4:z-1);
		}else if(m=="Forward"){
			switch(z){
				case 1:
					y++;
					break;
				case 2:
					x++;
					break;
				case 3:
					y--;
					break;
				case 4:
					x--;
					break;	
			}
		}
	}
	return {x,y};
}
