#include<bits/stdc++.h>

int N,M;
int MM[100][100];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};
inline bool cango(int x, int y){
    return x < N && x >= 0 && y < M && y >= 0 && MM[x][y] != -1; 
}
using namespace std;
signed main(){
    //cout << endl;
    for(int cnt = 1;cnt < 0x3f3f3f3f;cnt++){
        cin >> N >> M;
        if(N == 0 && M == 0){
            break;
        }
        //cout << N << M << endl;
        for(int i=0;i<N;i++){
            string tmp;cin >> tmp;  
            for(int j=0;j<M;j++){
                if(tmp[j] == '*'){
                    MM[i][j] = -1;
                } else {
                    MM[i][j] = 0;
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(MM[i][j] == -1){
                    for(int _ = 0;_ < 8;_++){
                        if(cango(i+dx[_], j+dy[_])){
                            MM[i+dx[_]][j+dy[_]]++;
                        }
                    }
                }
            }
        }
        if(cnt > 1)cout << endl;
        for(int i=0;i<N;i++){
            if(i==0)
                cout << "Field #" << cnt << ":" << endl;
            for(int j=0;j<M;j++){
                if(MM[i][j] == -1){
                    cout << '*';
                }else{
                    cout << MM[i][j];
                }           
            }
            cout << endl;
        }
    }

    

    return 0;
}