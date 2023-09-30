#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        vector<pair<int,int>> A;
        for(auto d:mp){
            A.push_back({d.second,d.first});
        }
        sort(A.begin(),A.end(),[&](pair<int,int> a,pair<int,int>b){
            if(a.first ==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        // for(auto c:A)cout<<c.first<<" "<<c.second<<endl;
        int mn = 1e15,mx = -1;
        int ans = 0;
        for(int i = 0;i<A.size();i++){
            mn = min(mn,A[i].second);
            mx = max(mx,A[i].second);
            ans+=(mx-mn)*A[i].first;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
