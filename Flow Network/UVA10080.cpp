#include<bits/stdc++.h>
#define endl '\n'
#define pb emplace_back
#define int long long
#define INF 0x3f3f3f
using namespace std;
const int N = 1040;
const int PREFIX = 520;
/*=====================================*/
struct Point {
  double x,y;
  //Point(double _x,double _y):x(_x),y(_y){}
  double to(Point a){
    return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
  }
}rats[N],holes[N];
double GetDistance(Point a, Point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
/*=====================================*/
int ratN,holeN,timeout,speed;
int used[N],matched[N];
vector<int> V[N];
//Point rats[N]={},holes[N]={};

bool dfs(int v){
  for(int pt : V[v]){
    if(used[pt])continue;
    used[pt] = 1;
    if(matched[pt]==-1 || dfs(matched[pt])){
      matched[pt] = v;
      return true;
    }
  }
  return false;
}
// x -> y :: Max c
void addEdge(int i,int j){
  V[i].pb(j+PREFIX);
  V[j+PREFIX].pb(i);
}
int solve(){
  //Konig
  memset(matched,-1,sizeof(matched));
  int ans = 0;
  for(int i=1;i<=ratN;i++){
    memset(used,0,sizeof(used));
    if(dfs(i))ans++;
  }
  return ans;
}
signed main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  while(cin >> ratN >> holeN >> timeout >> speed){
    for(int i=1;i<=N;i++)V[i].clear();
    for(int i=1;i<=ratN;i++){
      Point ppt ;
      double xx,yy;cin >> ppt.x >> ppt.y;
      rats[i] = ppt;
    }
    for(int i=1;i<=holeN;i++){
      Point ppt ;
      double xx,yy;cin >> ppt.x >> ppt.y;
      holes[i] = ppt;
    }
    for(int i=1;i<=ratN;i++){
      Point rat = rats[i];
      for(int j=1;j<=holeN;j++){
        Point hole = holes[j];
        if((rat.to(hole))/speed <= timeout){
          addEdge(i,j);
        }
      }
    }
    cout << ratN-solve() << endl;
  }
  return 0;
}
