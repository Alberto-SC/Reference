#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    for(auto &c:p)cin>>c;
    vector<bool> vis;
    vector<int> sz;
    for(int i = 0;i<n;i++){
        int cont = 1;
        while(p[i]!=i+1){
            swap(p[i],p[p[i]-1]);
            cont++;
        }
        if(cont>1)
            sz.push_back(cont);
    }
    int mx = 0,k2 = k,mn;
    for(auto c:sz){
        mx += 2*min(c/2,k2);
        k2-=min(c/2,k2);
    }
    for(auto c:sz){
        if(!k2)break;
        if(c&1)
            mx++,k2--;
    }

    sort(sz.begin(),sz.end());
    vector<int> a;
    int last = -1;
    for(int i = 0;i<sz.size();i++){
        if(sz[i]!=last){
            last = sz[i];
            a.push_back(last);
        }
    }
    vector<int> m(a.size());
    for(int i = 0;i<sz.size();i++){
        int idx = lower_bound(a.begin(),a.end(),sz[i])-a.begin();
        m[idx]++;
    }
    while(a.size()>0 && a.back()>k){
        a.pop_back();
    }
    if(a.size()==0){
        if(k)
            return cout<<k+1<<" "<<mx<<endl,0;
        else
        return cout<<0<<" "<<mx<<endl,0;
    }
    
    bitset<1000001> dp;
    dp.set(0);
    for(int i = 0;i<a.size();i++){
        m[i] = min(k/a[i],m[i]);
        for(int j = 0;(1<<j)<=m[i] ;j++){
            dp|= dp<<(a[i]*(1<<j));
            m[i]-=1<<j;
        }
        dp|= dp<<(a[i]*m[i]);
    }
    if(dp[k])mn = k;
    else mn = k+1;
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
