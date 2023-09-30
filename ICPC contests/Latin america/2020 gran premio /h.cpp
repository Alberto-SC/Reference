#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,g;
    cin>>n>>g;
    vector<int> nums(n);
    int total = 0;
    for(auto &c:nums)cin>>c,total+=c;
    
    vector<vector<int>> ans;
    int mn = n;
    for(int mask = 0;mask<(1<<n);mask++){
        int sum = 0;
        vector<int> id;
        int val = 0;
        for(int i = 0;i<n;i++){
            if((mask>>i)&1){
                id.push_back(i+1);
                sum+=nums[i];
                val|=(1<<i);
            }
        }
        if((sum*100)/total>=g){
            id.push_back((sum*100)/total);
            id.push_back(val);
            if(__builtin_popcount(mask)<mn){
                ans.clear();
                mn = __builtin_popcount(mask);
                ans.push_back(id);
            }
            else if(__builtin_popcount(mask)==mn){
                ans.push_back(id);
            }
        }
    }
    cout<<mn<<" "<<ans.size()<<endl;
    sort(ans.begin(),ans.end(),[&](vector<int> a,vector<int> b){
        return a.back()<b.back();
    });
    for(int i = 0;i<ans.size();i++){
        ans[i].pop_back();
        cout<<ans[i].back()<<" ";
        ans[i].pop_back();
        sort(ans[i].begin(),ans[i].end());
        for(int j = 0;j<mn;j++){
            cout<<ans[i][j];
            if(j!=mn-1)cout<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}