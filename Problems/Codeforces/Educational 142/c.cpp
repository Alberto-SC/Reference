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
        int ans = n/2;
        if(n ==1){
            cout<<0<<endl;
            continue;
        }
        vector<int> pos(n+7);
        for(int i = 0;i<n;i++){
            pos[nums[i]] = i;
        }

        int mx = 0,L,R;
        L = n/2;
        R = L+1;
        for(int i = L-1;i>=1;i--){
            if(pos[i]<pos[L])
                L--;
            else 
                break;
        }

        for(int i = R+1;i<=n;i++){
            if(pos[i]>pos[R])
                R++;
            else
                break;
        }

        int l = n/2;
        int r = l+1;
        if(pos[r]<pos[l]){
            cout<<ans<<endl;
        }
        else{
            int contr = n-R;
            int contl = L-1;
            ans =max(contr,contl);
            cout<<ans<<endl;
        }
    }
    return 0;
}
