#include<bits/stdc++.h>
#define int long long
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;

bool Table[30][30];
bool walked[30];

void dfs(int N);

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int now = 0;
	string A;
	getline(cin,A);

	for(int i = 0;i < 26;++i)
	{
		Table[i][i]=true;
	}

	for(int i = 0;i < A.length();++i)
	{
		if(A[i] == ',')
		{
			now++;
			continue;
		}

		int thi = A[i]-'A';

		Table[thi][now] = true;
	}

	string Q;
	getline(cin,Q);
	char temp;

	for(int i = 0;i < Q.length();++i)
	{
		int Ques = Q[i] - 'A';

		dfs(Ques);
		for(int j = 0;j < 26;++j)
		{
			if(Table[Ques][j])
			{
				temp = 'A';
				temp += j;
				cout << temp;
			}
		}
		cout << endl;
	}
}

void dfs(int N)
{
	if(walked[N])
		return;

		walked[N] = true;

		for(int i = 0;i < 26;++i)
		{
			dfs(i);
			if(Table[N][i])
			{
				Table[i][N] = true;
			}
		}
}
