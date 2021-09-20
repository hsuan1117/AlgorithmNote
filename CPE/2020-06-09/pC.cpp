#include<bits/stdc++.h>

using namespace std;

struct CMP{
    bool operator()(pair<char, int> a,pair<char, int> b){
        return a.second < b.second;
    }

};
map<char, int, CMP> c;

void reset(){
    c['A'] = 0;
    c['T'] = 0;
    c['C'] = 0;
    c['G'] = 0;
}

signed main(){
    int T;cin >> T;
    while(T--){
        int N,L;cin >> N >> L;
        vector<string> v;
        for(int i=0;i<N;i++){
            string x ;cin >> x;
            v.emplace_back(x);
        }

        for(int i=0;i<L;i++){
            reset();
            for(auto s:v){
                c[s[i]]++;
            }
            
        }
    }
    return 0;
}