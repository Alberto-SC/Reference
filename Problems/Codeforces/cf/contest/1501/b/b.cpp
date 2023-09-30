#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> d(n);
        for(int i = 0;i<n;i++){
            int l = (i-nums[i])+1;
            int r = i+1;
            if(l<0)l = 0;
            if(l<n)
                d[l]++;
            if(r<n)
                d[r]--;
        }
        for(int i =1;i<n;i++){
            d[i] = d[i]+d[i-1];
        }
        for(int i = 0;i<n;i++){
            if(d[i]>0)d[i] = 1;
            else d[i] = 0;
        }
        for(auto c:d)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
