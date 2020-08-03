#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define Mod 1000000007
using namespace std;

int x1,x2,n,q,ptr=1;
ll a[100000],ans;
struct Segment{
    int ls,rs;
    ll _max;
}seg[4*100000];

void build(int l,int r,int idx){
    if(l==r){
        seg[idx]._max = a[l];
        return;
    }
    int m = (l+r)>>1;
    int cl = seg[idx].ls = ptr++;
    int cr = seg[idx].rs = ptr++;
    build(l,m,cl);
    build(m+1,r,cr);
    seg[idx]._max = max(seg[cl]._max,seg[cr]._max);
}
void query(int l,int r,int idx){
    if(x1<=l&&r<=x2){
        ans = max(ans,seg[idx]._max);
        return;
    }
    int m = (l+r)>>1;
    if(x1<=m)query(l,m,seg[idx].ls);
    if(x2>m)query(m+1,r,seg[idx].rs);
}

int main(){
    cin >> n >> q;
    for(int i=0;i<n;i++)cin >> a[i];
    build(0,n-1,0);
    while(q--){
        cin >> x1 >> x2;
        if(x1>x2)swap(x1,x2);
        x1--; x2--;
        query(0,n-1,0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
