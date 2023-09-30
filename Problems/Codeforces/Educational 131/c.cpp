#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(vector<int> v,int x){
    int n = v.size();
    int fr = 0;
    for(int i = 0;i<n;i++){
        if(v[i]>x){
            fr-=v[i]-x;
        }
        else{
            fr+=(x-v[i])/2;
        }
    }
    if(fr>=0)return true;
    return false;
}

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(m);
        vector<int> v(n);
        for(auto &c:nums)cin>>c,c--,v[c]++;
        int l = 0,r = m*3;
        while(l+1<r){
            int M = (l+r)>>1;
            if(check(v,M))r = M;
            else l = M;
        }
        cout<<r<<endl;
    }
    return 0;
}