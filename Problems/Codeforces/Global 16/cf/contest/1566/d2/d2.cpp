#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n*m);
        for(auto &c:nums)cin>>c;
        map<int,vector<int>>mp;
        for(int i = 0;i<(n*m);i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> all_;
        for(auto &c:mp){
            reverse(c.second.begin(),c.second.end());
            all_.push_back(c.first);
        }
        vector<vector<int>> M(n,vector<int>(m));
        int c = 0;
        for(int i = 0;i<n;i++){
            int last = 0;
            for(int j = 0;j<m;j++){ 
                if(mp[all_[c]].size()==0){
                    reverse(M[i].begin()+last,M[i].begin()+j);
                    last = j;
                    c++;    
                }
                M[i][j] =mp[all_[c]].back();
                mp[all_[c]].pop_back();

            }
            reverse(M[i].begin()+last,M[i].end());
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<j;k++){
                    if(M[i][k]<M[i][j])ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

// 17 16 13 12 10 8 7 1 18
// 15 14 11 9  6  5 4 3 2 

