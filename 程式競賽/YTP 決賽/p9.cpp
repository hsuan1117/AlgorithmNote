#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll r,c,n;
struct str{
	ll x,y;
}arr[5005];
bool cmp(str a,str b){
	if(a.x<b.x)return 1;
	else if(a.x==b.x&&a.y<b.y)return 1;
	return 0;
}
bool cmp2(str a,str b){
	if(a.y<b.y)return 1;
	else if(a.y==b.y&&a.x<b.x)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>r>>c>>n;
	for(ll i=0;i<n;i++)cin>>arr[i].x>>arr[i].y;
	sort(arr,arr+n,cmp);
	ll xi=arr[0].x,yi=arr[0].y;
	for(ll i=1;i<n;i++){
		if(arr[i].x==xi&&arr[i].y-yi>1){
			cout<<"no\n";
			return 0;
		}
		xi=arr[i].x,yi=arr[i].y;
	}
	sort(arr,arr+n,cmp2);
	for(ll i=1;i<n;i++){
		if(arr[i].y==yi&&arr[i].x-xi>1){
			cout<<"no\n";
			return 0;
		}
		xi=arr[i].x,yi=arr[i].y;
	}
	cout<<"yes\n";
	return 0;
}
