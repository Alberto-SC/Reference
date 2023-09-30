#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(4*n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        vector<pair<int,int>> v;
        for(auto c:mp){
            v.push_back(c);
        }
        int r = v.size()-1;
        int l = 0;
        int A = v[l].first*v[r].first;
        bool flag = true;
        while(l<=r){
            int a = v[l].first*v[r].first;
            if(a!=A)flag = false;
            if(l==r){
                if(v[l].second%4)flag = false;
            }
            else{
                if(v[l].second!=v[r].second || v[l].second&1)flag = false;
            }
            l++,r--;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}