#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;

// ref: http://web.ntnu.edu.tw/~algo/Subsequence2.html#3
int LCS(vector<int> &seq, vector<int> &seq2){
    if(seq.size() == 0 || seq2.size() == 0)return 0;

    vector<int> p[128];

    for(int i = 0; i < seq2.size(); i++){
        p[seq2[i]].pb(i);
    }

    vector<int> v; v.pb(-1);

    for(int i = 0;i < seq;i++){
        for(int j = p[seq[i]] -1;j>=0;j--){
            int n = p[seq.at(i)][j];

            if(n > v.back()){
                v.pb(n);
            } else {
                *lower_bound(v.begin(), v.end(), n) = n;
            }
        }
    }
    return v.size()-1;
}

int main(){

    return 0;
}