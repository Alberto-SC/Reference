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
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        int mex = 0,mx = 0;
        for(int i = 0;i<n;i++)
            mx = max(mx,nums[i]),mp[nums[i]]++;
        for(int i = 0;i<=100007;i++)
            if(mp.count(i)==0){mex = i;break;}
        
        int nw = ((mx+mex)/2)+ ((mx+mex)%2);
        if(k==0)cout<<n<<endl;
        else if(nw ==mex)
            cout<<n+k<<endl;
        else if(nw<=mx && mp.count(nw))cout<<n<<endl;
        else if(nw<=mx && mp.count(nw)==0)cout<<n+1<<endl;
    }
    return 0;
}  
