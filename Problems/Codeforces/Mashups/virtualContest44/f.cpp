#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int k;
bool check(int x,int r,vector<pair<int,int>> &ac,vector<pair<int,int>> &ac2){
    int l =lower_bound(ac.begin(),ac.end(),make_pair(x,-1ll))-ac.begin();
    int idx = lower_bound(ac.begin(),ac.end(),make_pair(r,-1ll))-ac.begin();
    int y = r*(ac[l].second-ac[idx].second);
    y-= (ac2[l].second-ac2[idx].second);
    return y<=k;
}

int get_max(int x,int r,vector<pair<int,int>> &ac,vector<pair<int,int>> &ac2){
    int l =lower_bound(ac.begin(),ac.end(),make_pair(x,-1ll))-ac.begin();
    int idx =lower_bound(ac.begin(),ac.end(),make_pair(r,-1ll))-ac.begin();
    int y = r*(ac[l].second-ac[idx].second);
    y-= (ac2[l].second-ac2[idx].second);
    int ans = ac[l].second-(idx+1<ac.size()?ac[idx+1].second:0);
    int res = k-y;
    l--;
    // cout<<l<<" "<<ans<<" "<<res<<endl;
    if(l>=0)
        ans+=res/(ac[idx].first-ac[l].first);
    return ans;
}


signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        map<int,int> mp;
        int offset = 0;
        for(auto &c:nums)cin>>c,mp[c]++,offset = min(offset,c);
        vector<pair<int,int>> x;
        for(auto c:mp){
            x.push_back({c.first+abs(offset),c.second});
        }
        vector<pair<int,int>> ac(x.size());
        vector<pair<int,int>> ac2(x.size());
        for(int i = x.size()-1;i>=0;i--){
            ac[i] = {x[i].first,x[i].second+(i==x.size()-1?0:ac[i+1].second)};
            ac2[i] = {x[i].first,(x[i].first*x[i].second)+(i==x.size()-1?0:ac2[i+1].second)};
        }
        // for(auto c:ac)cout<<c.first<<" "<<c.second<<endl;
        // cout<<endl;
        // for(auto c:ac2)cout<<c.first<<" "<<c.second<<endl;
        int ans = 0,number;
        for(int i = 0;i<x.size();i++){
            int l = -1,r = x[i].first;
            while(l+1<r){
                int m = (l+r)>>1;
                if(check(m,x[i].first,ac,ac2))
                    r = m;
                else 
                    l = m;
            }
            if(get_max(r,x[i].first,ac,ac2)>ans){
                ans = max(ans,get_max(r,x[i].first,ac,ac2));
                number = x[i].first;
            }
        }
        cout<<ans<<" "<<number+offset<<endl;
    }
    return 0;
}  
