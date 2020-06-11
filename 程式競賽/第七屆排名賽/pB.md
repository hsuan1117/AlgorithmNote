# pB 重組迴文
  *[pB](pB.pdf)
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int n;
string s;
bool check(int x,int y,string str){
    if(x==y)return true;
    for(int i=x,j=y;i<=j;i++,j--){
        if(str[i]!=str[j])return false;
    }
    return true;
}

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        if(check(i,n-1,s)){
            cout << i << endl;
            break;      
        }
    } 
    return 0;
}
```
