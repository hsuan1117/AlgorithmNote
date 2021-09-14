#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x,y;
	
};
inline bool operator <(Point a, Point b){
	return a.x < b.x;
}
set<Point> all;
signed main(){
	int x,y;
	while(cin >> x >> y){
		all.emplace(Point{x,y});
	}
	for(auto &xx : all)cout << xx.x << " " << xx.y << endl;
}
