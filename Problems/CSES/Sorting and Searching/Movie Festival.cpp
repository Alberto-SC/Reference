#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
        sort(nums.begin(),nums.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        int cont  =1;
        int last = nums[0].second;
        for(int i = 1;i<n;i++){
            if(nums[i].first>=last){
                cont++;
                last = nums[i].second;
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}