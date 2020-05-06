#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int bit[26][maxn];

int sum(int idx,int who){
    int res = 0;
    for(++idx;idx>0;idx -= idx& -idx)res+=bit[who][idx];
    return res;
}

void add(int idx,int val,int who){
    for(++idx;idx<n;idx += idx & -idx)bit[who][idx]+=val;
}

int main(){
    int n,t,l,r;
    string s;
    cin>>s;
    n = s.size();
    for(int i = 0;i<n;i++)
        add(i,1,s[i]-'a')
    cin>>m;
    for(int i = 0;i<n;i++){
        cin>>t;
        if(t == 1){
            char c;
            cin>>l>>c;
            add(l,-1,s[l]-'a');
            s[l] = c;
            add(l,1,s[l]-'a');
        }
        if(t == 2){
            int ans = 0;
            for(int i = 0;i<26;i++){
                ans+= sum(r,i)-sum(l-1,i);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}