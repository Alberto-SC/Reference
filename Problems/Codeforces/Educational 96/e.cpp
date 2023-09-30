#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> bit(maxn);

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}
void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}
int sum(int l,int r){
    return sum(r)-sum(l-1);
}

signed main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        string s,t;
        cin>>s;
        t = s;
        reverse(t.begin(),t.end());
        vector<int> p(n);
        vector<vector<int>> pos(26);
        for(int i = 0;i<n;i++)
            pos[t[i]-'a'].push_back(i);
        for(int i = 0;i<26;i++){
            if(pos[i].size()==0)continue;
            reverse(pos[i].begin(),pos[i].end());
        }
        for(int i = 0;i<n;i++){
            p[i] = pos[s[i]-'a'].back();
            pos[s[i]-'a'].pop_back();
        }
        int inv = 0;
        for(int i = 0;i<n;i++){
            inv += sum(p[i]+1,n);
            add(p[i],1);
        }
        cout<<inv<<endl;
    }
    return 0;
}

