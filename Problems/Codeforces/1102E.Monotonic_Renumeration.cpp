#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 998244353 ;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    map<int,vector<int>> mp;
    for(int i = 0;i<n;i++)
        mp[nums[i]].push_back(i);
    vector<pair<int,int>> V;
    for(auto c:mp)
        V.push_back({c.second[0],c.second.back()});

    sort(V.begin(),V.end());
    int disjoint = 1,l = V[0].first,r = V[0].second;
    for(int i = 1;i<V.size();i++){
        if(V[i].first<r)
            r = max(r,V[i].second);
        else{
            l = V[i].first;
            r = V[i].second;
            disjoint++;
        }
    }
    cout<<mod_pow(2,disjoint-1)<<endl;


    return 0;
}   