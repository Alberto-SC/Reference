#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mn = 1e15,mx = -1;
        for(int i  = 1;i<n;i++){
            mn = min(mn,abs(nums[i]-nums[i-1]));
            mx = max(mx,abs(nums[i]-nums[i-1]));
        }
        if(mx-mn>4)cout<<-1<<endl;
        else if(n ==1 || n==2)cout<<0<<endl;
        else {
            int ans = n+1;
            for(int diff = mn-2;diff<=mx+2;diff++){
                for(int j = -1;j<=1;j++){
                    for(int k = -1;k<=1;k++){
                        int start = nums[0]+j;
                        int res = abs(nums[0]-start);
                        for(int i = 1;i<n;i++){
                            start+=diff*k;
                            if(abs(nums[i]-start)>1)res = 1e15;
                            res+=abs(nums[i]-start);
                        }
                        ans = min(ans,res);
                    }
                }
            }
            if(ans>n)cout<<-1<<endl;
            else
                cout<<ans<<endl;
        }

    }
    return 0;
}  



Actividades 
