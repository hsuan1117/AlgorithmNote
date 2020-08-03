#include<iostream>
#include<vector>
#include<string.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define endl '\n'
#define INF 0x3f3f3f
using namespace std;
int N,Q;
int Tree[20000000+5];
int Data[2000000];
int nearBy(int n){
	int i=1,j=2;
	for(;i>n||j<n;i*=2,j*=2);
	return j;
}
void modify(int pos,int x){
	pos += N;
	Tree[pos] = x;
	for(;pos > 1;pos/=2){
		// pos ^ (XOR) 1 ==> 旁邊的節點
		Tree[pos/2] = max(Tree[pos],Tree[pos^1]);
	}
}
int query(int L,int R){
	if(L==R)return Tree[L+N-1];
	if(L-R == 1 || L-R == -1){
		return max(Tree[L+N-1],Tree[R+N-1]);
	}
	int res = -1e9;
	L += N ; R += N;
	for(;L<R;L/=2,R/=2){
		if(L % 2 == 0) res = max(res, Tree[L++]);
		if(R % 2 == 0) res = max(res, Tree[--R]);
	}
	return res;
}
void build(){
	for(int i=0;i<N;i++)Tree[i+N] = Data[i];
	for(int i=N-1;i>0;i--)Tree[i] = max(Tree[2*i] , Tree[2*i+1]);
	//for(int i=1;i<=2*N;i++)cout << Tree[i] << " ";
	//cout << endl;
}
int main(){
	// Build
	cin >> N >> Q;
	mem(Tree,-1e9);
	mem(Data,-1e9);
	for(int i=0;i<N;i++)cin >> Data[i];
	N = nearBy(N);
	build();
	while(Q--){
		int askL , askR ;
		cin >> askL >> askR ;
		cout << query(askL,askR) << endl;
	}
	//for(int i=1;i<=2*N;i++)cout << Tree[i] << " ";
	return 0;
}




/********************
10 5
4 0 17 13 14 15 6 2 17 10
5 5
5 7
3 9
1 2
1 7



*********************/
