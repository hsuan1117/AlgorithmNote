#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin >> n;
    // 1 5 10 50
    for(int i=0;i<n;i++){
         int x; cin >> x;
         int _50 = x / 50;
         int _10 = (x%50) / 10;
         int _5  = ((x%50)%10) / 5;
         int _1  = (((x%50)%10)%5) / 1;
         cout << _50+_10+_5+_1 << endl;
    }
    
    

    return 0;
}
