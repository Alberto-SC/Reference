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
        vector<int> idx(n+1);
        for(int i = 0;i<n;i++){
            idx[nums[i]] =i;
        }
        int l = idx[1],r = idx[1];
        string ans(n,'0');
        ans[0] = '1';
        for(int i = 2;i<=n;i++){
            if(idx[i]>r)
                r = idx[i];
            if(idx[i]<l)
                l = idx[i];
            if((r-l)+1== i)ans[i-1]='1'; 
        }
        cout<<ans<<endl;
    }
    return 0;
}  

