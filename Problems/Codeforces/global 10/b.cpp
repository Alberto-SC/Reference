#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<lli> nums(n);
        lli mn = 1000000007,mx = mn*-1;
        for(auto &c:nums)cin>>c,mn = min(mn,c),mx = max(mx,c);
        if(mx == mn){
            for(int i = 0;i<n;i++)cout<<0<<" ";
            cout<<endl;
        }
        else if(k==1){
            for(lli i = 0;i<n;i++)cout<<mx-nums[i]<<" ";
            cout<<endl;
        }
        else {
            for(lli i = 0;i<n;i++)nums[i]= mx-nums[i];
            mx = mx-mn;
            k--;
            for(lli i = 0;i<n;i++)nums[i]= mx-nums[i];
            if(k&1){
                for(lli i = 0;i<n;i++)cout<<nums[i]<<" ";
                cout<<endl;
            }
            else {
                for(lli i= 0;i<n;i++)cout<<mx-nums[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}

