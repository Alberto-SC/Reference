#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pos(n+1,n);
        for(int i = 0;i<n;i++){
            pos[nums[i]] = i;
        }        

        int l = pos[0];
        int r = pos[0];

        
        vector<int> ans(n+1);



        int id = 1;
        while(id<=n){
            while(pos[id]>=l && pos[id]<=r){
                ans[id] = 0;
                id++;
            }


            if(pos[id]>r){
                ans[id] = (pos[id]-r)*(l+1);
                r = pos[id];
            }
            else{
                ans[id] = (l-pos[id])*(n-r);
                l = pos[id];
            }
            id++;
        }
        for(int i = 1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}