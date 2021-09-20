#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std ;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    int r = 1;
    while(cin>>n>>m&&(n||m)){
        int cnt[n][m];
        int d[] = {-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt[i][j] = 0;
            }
        }
        char mp[n][m];
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            for(int j=0;j<m;j++){
                mp[i][j] = str[j];
                if(str[j]=='*'){
                    for(int x:d){
                        for(int y:d){
                            if(i+x>=0&&i+x<n&&j+y>=0&&j+y<m){
                                cnt[i+x][j+y]++;
                            }
                        }    
                    }
                }
            }
        }
        if(r!=1){
            cout<<endl<<endl;
        }
        cout<<"Field #"<<r++<<":";
        for(int i=0;i<n;i++){
            cout<<endl;
            for(int j=0;j<m;j++){
                if(mp[i][j]=='*'){
                    cout<<'*';
                }else{
                    cout<<cnt[i][j];
                }
            }      
        }
    }


    return 0;
}