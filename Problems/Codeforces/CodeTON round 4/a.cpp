#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        bool flag = false;
        for(auto &c:nums)cin>>c;
        
        for(int i = 0;i<n;i++){
            if(i>=nums[i]-1)flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


