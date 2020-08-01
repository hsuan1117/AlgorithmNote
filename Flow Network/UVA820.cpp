#include<bits/stdc++.h>
#define endl '\n'
#define pb emplace_back
#define int long long
#define INF 0x3f3f3f
using namespace std;

const int N = 110;
int nnn;
vector<tuple<int, int,int> > Edges[N];
int used[N];
int Start,End;
int dfs(int v,int f){
  //cout << v << endl;
  if(v == End)return f;
  used[v] = 1;
  for(auto &x : Edges[v]){
    int e, w;
    int ig;
    // e,w = 反向
    tie(e,w,ig) = x;//Edges[get<2>(x)];
    if(used[e] || w == 0)continue;
    w = dfs(e,min(w,f));
    if(w > 0){
      get<1>(x) -= w;
      get<1>(Edges[e][ig]) += w;
      return w;
    }
  }
  return 0;
}
// x -> y :: Max c
void addEdge(int x, int y, int c){
  // 到 y , Max c , 反向邊
  Edges[x].pb(y , c, Edges[y].size());
  Edges[y].pb(x , c, Edges[x].size()-1);
}
int ffa(int s,int e){
  int ans = 0;
  Start = s;End = e;
  while(1){
    int f;
    for(int i=0;i<=nnn;i++)used[i] = 0;
    f = dfs(s, INF);
    if(f<=0)break;
    ans+=f;
  }
  return ans;
}
signed main(){
  //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  int __times__ = 0;
  while(cin >> nnn&&nnn){
    __times__++;
    for(int i=0;i<=nnn;i++)Edges[i].clear();
    int ss,ee,nn;cin >> ss >> ee >> nn;
    while(nn--){
      int a,b,w;
      cin >> a >> b >> w;
      addEdge(a,b,w);
    }
    cout << "Network " << __times__ << endl;
    cout << "The bandwidth is " <<  ffa(ss,ee) << "." << endl<<endl;
  }
  return 0;
}
