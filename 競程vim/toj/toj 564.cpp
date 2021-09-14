#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;

int N;
vector<int> m[1000];

int D;
bool vis[1000];
int dfs(int x){
    if(vis[x])return;
    vis[x] = true;

    for(int a:m[x]){
        dfs(a);
    }
}

signed main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;cin >> a >> b;
        m[a].pb(b);
        m[b].pb(a);
    }

    int m;cin >> m;
    for(int i=0;i<m;i++){
        cin >> D;
        dfs(D);
    }
    return 0;
}