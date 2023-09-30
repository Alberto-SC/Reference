#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,l,r;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> ml,mr;
        for(int i = 0;i<l;i++)
            ml[nums[i]]++;
        for(int i = l;i<n;i++)
            mr[nums[i]]++;
        vector<int> to_erase;
        for(auto c:ml){
            if(mr.count(c.first)){
                int mn = min(c.second,mr[c.first]);
                mr[c.first]-=mn;
                c.second-=mn;
                r-=mn;
                l-=mn;
                if(mr[c.first]==0)mr.erase(c.first);
                if(c.second==0)to_erase.push_back(c.first);
            }
        }
        for(auto d:to_erase)ml.erase(d);
        to_erase.clear();
        vector<pair<int,int>> vl;
        vector<pair<int,int>> vr;
        for(auto c:ml){
            vl.push_back(c);
        }
        for(auto c:mr){
            vr.push_back(c);
        }
        int ans = 0;
        if(l ==r)
            ans =l;
        else if(l>=r){
            int idx= 0;
            while(idx<vl.size() && l>=r){ 
                if(vl[idx].second>=2){
                    int y = min(vl[idx].second-(vl[idx].second&1),l-r);
                    l-=y;
                    ans+=y/2;
                }
                idx++;
            }
            cout<<l<<" "<<r<<endl;
            ans+=l;
        }
        else{
            int idx= 0;
            while(idx<vr.size() && r>=l){ 
                if(vr[idx].second>=2){
                    int y = min(vr[idx].second-(vr[idx].second&1),r-l);
                    r-=y;
                    ans+=y/2;
                }
                idx++;
            }
            ans+=r;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
