#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
    int T = 1,n;
    cin>>n;
    vector<int> nums(n);
    vector<int> f(n+1);
    for(auto &c:nums)cin>>c,f[c]++;
    
    vector<int> ac(n+1);
    for(int i= 1;i<=n;i++){
        ac[i] = f[i]+ac[i-1];
    }

    int ans = 0;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        int x = nums[i];
        if(x == 1){
            // ans+= ((n-1)*(n-2))/2;
            continue;
        }
        int mul = 0;
        vector<int> rev;
        for(int j = 2*x;j<=n;j+=x){
            if(f[j]){
                rev.push_back(j);
                mul++;
            }

        }
        int c = ac[n]-ac[x];
        c-=mul;
        cout<<x<<" "<<c<<endl;
        int res = (c*(c-1))/2;
        // ans+= (c*(c-1))/2;
        cout<<res<<endl;
        for(int j= rev.size()-1;j>=0;j--){
            cout<<rev[j]<<" "<<(ac[n]-ac[rev[j]-1])-(rev.size()-j)<<endl;
            res+= (ac[n]-ac[rev[j]-1])-(rev.size()-j);
        }   
        cout<<"FINAL "<<res<<endl;
        ans+=res;
        
    }
    cout<<ans<<endl;

    return 0;
}