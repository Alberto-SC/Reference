#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        bool flag= false,even = false;
        int cont = 0;
        for(int i = 1;i<n-1;i++){
            ans+=(nums[i]+1)/2;
            if(nums[i]==1)cont++;
        }
        if(n==3 && nums[1]&1)cout<<-1<<endl;
        else if(cont == n-2)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}






