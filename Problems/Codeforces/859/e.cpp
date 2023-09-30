#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
         

        vector<int> pref(n);
        pref[0] = nums[0];
        
        for(int i = 1;i<n;i++)
            pref[i] = pref[i-1]+nums[i]; 
        
        int l = -1,r = n-1;
        while(l+1<r){
            int m = (l+r)>>1;
            
            int exp = pref[m];

            cout<<"? "<<m+1<<" ";
            for(int i = 0;i<=m;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            int ans;
            cin>>ans;
            if(ans>exp)r = m;
            else l = m;
        }
        cout<<"! "<<r+1<<endl;
    }
    return 0;
}

