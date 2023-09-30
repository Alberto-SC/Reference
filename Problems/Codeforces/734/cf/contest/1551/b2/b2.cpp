#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        vector<int> b[n+1];
        for(auto &c:nums)cin>>c;
        for(int i = 0 ;i<n;i++)
            b[nums[i]].push_back(i);
        vector<int> ans(n);
        vector<bool> used(n+1);
        for(int i = 0;i<=n;i++){
            if(b[i].size()>=k){
                int aux = k;
                while(aux--){
                    ans[b[i].back()] = aux+1;
                    b[i].pop_back();
                }
                used[i] = true;
            }
        }
        vector<int> f;
        for(int i = 0;i<=n;i++){
            if(used[i])continue;
            for(auto c:b[i])
                f.push_back(c);
        }
        int x = f.size()/k;
        x*=k;
        for(int i = 0;i<x;i++){
            ans[f[i]] = (i%k)+1;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
