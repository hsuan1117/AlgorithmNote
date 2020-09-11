#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> graph[800+5];
int vis[800+5] = {0};
queue<int> q;

signed main(){
    memset(graph,0,sizeof(graph));

    int N,M;cin >> N >> M;

    for(int i=0;i<M;i++){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
    }

    int s,e;cin >> s >> e;
    for(auto x : graph[s]){
        q.push(x);
        vis[x] = true;
    }
    while(!q.empty()){
        if(q.front() == e){
            break;
        }
        for(auto x : graph[q.front()]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
        q.pop();
    }
    cout << (vis[e]?"Yes":"No") << endl;
    return 0;
}
