#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb emplace_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;

bool Map[1025][1025];

int x[8]={-1,-1,-1,0,1,1,1,0};
int y[8]={1,0,-1,-1,-1,0,1,1};

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
  cin >> a >> b;
	for(int i = 1;i <= a;++i)
	{
		for(int j = 1;j <= b;++j)
		{
			cin >> Map[i][j];
		}
	}
	int val;

	for(int i = 1;i <= a;++i)
	{
		for(int j = 1;j <= b;++j)
		{
	val=0;
			for(int k = 0;k < 8;++k)
			{

				if(Map[i+x[k]][j+y[k]])
				{
					val++;
				}

			}
				cout << val <<" ";
		}
		cout << endl;
	}
}
