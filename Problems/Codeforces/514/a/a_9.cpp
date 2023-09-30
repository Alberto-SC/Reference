#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,L,a;
    while(t--){
        cin>>n>>L>>a;
        vector<pair<int,int>> nums(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i].first>>nums[i].second;
        }
        nums.push_back({L,0});
        int last = 0;
        int cont = 0;
        for(int i = 0;i<=n;i++){
            cont+=(nums[i].first-last)/a;
            last=nums[i].first+nums[i].second;            
        }
        cout<<cont<<endl;
    }
    return 0;
}  
