#include<bits/stdc++.h>
#define endl '\n'
#define pb emplace_back
#define int long long
#define INF 0x3f3f3f
using namespace std;

const int maxN = (int)1e7+5;
int nums[maxN];
int cnt = 0;

//Node Tree[maxN * 4]
struct Node {
  //左界 、 右界
  int L,R;
  int min,max;
  //鄰居節點
  Node *left,*right;
} Tree[maxN << 2];
std::ostream& dump(std::ostream &o, const Node& p)
{
  return o << "\tL: " << p.L << "  R: " << p.R << endl<< "\tmin: " << p.min << "  max: " << p.max << endl;
}
std::ostream& operator << (std::ostream &o,const Node &a){
  return dump(o,a);
}
void build(int left,int right,Node *node=Tree){
  //cout << "Run build" << left << "," << right << " => ";
  node->L = left;
  node->R = right;
  if(left==right){
    //葉節點
    node->min = node->max = nums[left];
    //cout << nums[left] << endl;
    return;
  }
  //cout << endl;
  node->left = ++cnt+Tree;
  node->right = ++cnt+Tree;

  int m = (left+right)/2;
  build(left,m,node->left);
  build(m+1,right,node->right);
  node->max = max(node->left->max,node->right->max);
  node->min = min(node->left->min,node->right->min);
}

void update(int id,int x,Node *node=Tree){
  if(node->left == node->right){
    node->min = node->max = x;
    nums[id] = x;
    return;
  }
  int m = (node->L + node->R)/2;
  build(node->L,m,node->left);
  build(m+1,node->R,node->right);
  node->max = max(node->left->max,node->right->max);
  node->min = min(node->left->min,node->right->min);
}


int askL , askR;
int ans;
enum QueryMethod:int {
    MAX,MIN
};
void query(int left,int right,Node *node=Tree,QueryMethod method=QueryMethod::MAX){
  //cout << "Run query: " << left << "," << right << *node << endl;
  if(askL<=left && right<=askR){
    switch(method){
      case QueryMethod::MAX:
        ans = max(node->max,ans) ;
      case QueryMethod::MIN:
        ans = min(node->min,ans) ;
    }
    return ;
  }
  int m = (left+right)/2;
  if(askL<=m) query(left,m,node->left,method);
  if(m<askR)  query(m+1,right,node->right,method);
  //return max(query(left,m,node->left),query(m+1,right,node->right));
}

signed main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int N,ask;cin >> N >> ask;
  for(int i=0;i<N;i++)cin >> nums[i];
  build(0,N-1);
  //cout << "========" << endl;
  for(int i=0;i<2*N;i++){
    //cout << "["<< i << "] " <<endl<< Tree[i] << endl;
  }
  while(ask--){
    cin >> askL >> askR;
    askL-=1;askR-=1;
    if(askL > askR)swap(askL,askR);
    ans=INF;
    query(0,N-1);
    cout << ans << endl;
    ans=0;
  }
  return 5,2,0,10,0;
}
/*
10 5
4 0 17 13 14 15 6 2 17 10
5 5
5 7
3 9
1 2
1 7
*/
