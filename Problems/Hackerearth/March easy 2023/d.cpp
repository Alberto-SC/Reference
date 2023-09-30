#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        vector<int> bits[20];
        vector<int> z[20];
        for(auto &c:nums)cin>>c;

        for(int i = 0;i<20;i++){
            bits[i].resize(n+1);
            bits[i].back() = n;
            z[i].resize(n+1);
            z[i].back() = n;
            for(int j = n-1;j>=0;j--){
                if((nums[j]>>i)&1){
                    
                    bits[i][j] = bits[i][j+1];
                    z[i][j] = j;
                }
                else {  
                    z[i][j] = z[i][j+1];
                    bits[i][j] = j;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            int mn = 1e9;
            for(int b = 0;b<20;b++){
                if((nums[i]>>b)&1)mn = min(mn,bits[b][i]);
                else mn = min(mn,z[b][i]);
            }
            ans+=mn-i;
        }
        cout<<ans-n<<endl;
    }
    return 0;
}

