#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ac(n);
        for(int i = 0;i<n;i++){
            if(!i)ac[i] = nums[i];
            else ac[i] = ac[i-1]+nums[i];
        }
        int ans = n+1;
        for(int i = 0;i<n;i++){
            int b = ac[i];
            int x =  1;
            bool flag = false;
            for(int j = i;j<n;j++){
                if(ac[j]== b*x){x++;if(j == n-1)flag = true;};
            }
            // cout<<b<<" "<<x<<endl;
            if(flag)ans = min(ans,n-(x-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}  

