#include<bits/stdc++.h>
using namespace std;

signed main(){
    int K;
    while(cin >> K && K != 0){
        int N,M;cin >> N >> M;
        while (K--)
        {
            int x,y;
            cin >> x >> y;
            if(x > N && y > M){
                cout << "NE" << endl;
            } else if(x < N && y > M){
                cout << "NO" << endl;
            } else if(x > N && y < M){
                cout << "SE" << endl;
            } else if(x < N && y < M){
                cout << "SO" << endl;
            } else {
                cout << "divisa" << endl;
            }
        }

    }
    return 0;
}