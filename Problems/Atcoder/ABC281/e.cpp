#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k,m;
    while(T--){
        cin>>n>>m>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        set<pair<int,int>> a;
        set<pair<int,int>> b;
        vector<int> ans((n-m)+1);
        int sum = 0;
        for(int i = 0;i<m;i++){
            if(a.size()<k){
                a.insert({nums[i],i});
                sum+=nums[i];
            }
            else{
                int mx = a.rbegin()->first;
                int id = a.rbegin()->second;
                if(nums[i]<mx){
                    a.erase(a.find({mx,id}));
                    sum-=mx;
                    a.insert({nums[i],i});
                    sum+=nums[i];
                    b.insert({mx,id});
                }
                else{
                    b.insert({nums[i],i});
                }
            }
        }
        ans[0] = sum;
        for(int i = 0;i<n-m;i++){
            if(a.find({nums[i],i})!=a.end()){
                a.erase(a.find({nums[i],i}));
                sum-=nums[i];
                int mn = b.size()==0?1e12:b.begin()->first;
                int id = b.size()==0?0:b.begin()->second;
                if(nums[i+m]<mn){
                    a.insert({nums[i+m],i+m});
                    sum+=nums[i+m];
                }
                else{
                    a.insert({mn,id});
                    sum+=mn;
                    b.erase(b.begin());
                    b.insert({nums[i+m],i+m});
                }
            }
            else{
                b.erase(b.find({nums[i],i}));
                int mx = a.rbegin()->first;
                int id = a.rbegin()->second;
                if(nums[i+m]<mx){
                    a.erase(a.find({mx,id}));
                    sum-=mx;
                    a.insert({nums[i+m],i+m});
                    sum+=nums[i+m];
                    b.insert({mx,id});
                }
                else{
                    b.insert({nums[i+m],i+m});
                }
            }
            ans[i+1] = sum;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}