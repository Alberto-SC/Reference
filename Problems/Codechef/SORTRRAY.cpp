#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> b(n);
        iota(b.begin(),b.end(),100000);
        vector<int> diff(n);
        for(int i = 0;i<n;i++)
            diff[i] = b[i]-nums[i];
        
        int ans = 0,q;
        for(int i = 0;i<19;i++){
            int cont = 0;
            for(int j = 0;j<n;j++)
                if((diff[j]>>i) &1)
                    cont++;
            if(cont)ans++;
        }
        cout<<ans<<endl;
        for(int i = 0;i<19;i++){
            vector<int> ans;
            for(int j = 0;j<n;j++)
                if((diff[j]>>i) &1)
                    ans.push_back(j+1);

            if(ans.size()==0)continue;
            cout<<ans.size()<<" "<<(1<<i)<<endl;
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}
