#include<bits/stdc++.h>
using namespace std;
int N,T;
long long Ri[10000005];
long long arr[40000005];
int A,B;
void build(int l,int r,int idx){
    if(l>=r){
        arr[idx]=Ri[l];
        return;
    }
    int m=(l+r)>>1;
    build(l,m,idx<<1);
    build(m+1,r,idx<<1|1);
    arr[idx]=max(arr[idx<<1],arr[idx<<1|1]);
}
long long  Find(int l,int r,int idx){
    if(A<=l&&r<=B)return arr[idx];
    int m=(l+r) >> 1;
    if(m>=B)return Find(l,m,idx << 1);
    if(A>m)return Find(m+1,r,idx<<1|1);
    return max(Find(l,m,idx << 1),Find(m+1,r,idx<<1|1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>T;
    for(int i=1;i<=N;i++)cin>>Ri[i];
    build(1,N,1);
    for(int i=0;i<T;i++){
        cin>>A>>B;
        if(A>B){
        	swap(A,B);
		}
        cout<<Find(1,N,1)<<'\n';
    }
    return 0;
}
