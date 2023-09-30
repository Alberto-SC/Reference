#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,x,m;
    cin>>n>>m;
    map<int,int> mp;
    int q[1000007],top = 0;
    for(int i = 0;i<n;i++){
        cin>>x;
        q[top++] = x;
        mp[x]= 0;
    }
    vector<int> ans;
    lli res = 0;
    for(int i = 0;i<top;i++){
        if(ans.size()==m)break;
        int u = q[i];
        if(!mp.count(u-1))
            mp[u-1] = mp[u]+1,q[top++] = u-1;
        if(!mp.count(u+1))
            mp[u+1] = mp[u]+1,q[top++] = u+1;
        if(mp[u]!= 0){
            res+=mp[u];
            ans.push_back(u);
        }
    }
    cout<<res<<endl;
    for(auto &c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}