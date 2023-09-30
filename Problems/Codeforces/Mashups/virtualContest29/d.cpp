#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,l;
    while(t--){
        cin>>n;
        vector<pair<int,int>> seg;
        for(int i = 0;i<n;i++){
            cin>>x>>l;
            seg.push_back({x,l});
        }
        sort(seg.begin(),seg.end());
        vector<int> alive(n);
        for(int i = 0;i<n;i++){
            int idx = lower_bound(seg.begin(),seg.end(),make_pair(seg[i].first-seg[i].second,0ll))-seg.begin();
            idx--;
            if(idx<0)alive[i] = 1;
            else 
                alive[i] = alive[idx]+1;
        }
        int ans = 0;
        for(int i = n-1;i>=0;i--)
            ans = max(ans,alive[i]);
        // for(auto c:alive)cout<<c<<" ";
        // cout<<endl;
        cout<<n-ans<<endl;
    }
    return 0;
}  
