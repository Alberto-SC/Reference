#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int bit[26][maxn];
int n;
int sum(int idx,int who){
    int res = 0;
    for(++idx;idx>0;idx -= idx& -idx)res+=bit[who][idx];
    return res;
}

void add(int idx,int val,int who){
    for(++idx;idx<maxn;idx += idx & -idx)bit[who][idx]+=val;
}

int main(){
    int l,r,m,t;
    string s;
    cin>>s;
    n = s.size();
    for(int i = 0;i<n;i++)
        add(i,1,s[i]-'a');
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>t;
        if(t == 1){
            char c;
            cin>>l>>c;
            l--;
            add(l,-1,s[l]-'a');
            s[l] = c;
            add(l,1,s[l]-'a');
        }
        if(t == 2){
            cin>>l>>r;
            l--;
            r--;
            int ans = 0;
            for(int i = 0;i<26;i++){
                // cout<<sum(r,i)<<" "<<sum(l-1,i)<<endl;
                ans+= (sum(r,i)-sum(l-1,i))>0;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}