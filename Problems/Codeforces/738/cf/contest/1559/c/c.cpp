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
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(nums[n-1]==0){
            for(int i = 1;i<=n+1;i++)
                cout<<i<<" ";
            cout<<endl;
        }
        else if(nums[0]==1){
            cout<<n+1<<" ";
            for(int i = 1;i<=n;i++)
                cout<<i<<" ";
            cout<<endl;
        }
        else{
            bool flag  = false;
            for(int i = 1;i<=n;i++){
                if(!flag && nums[i-1]== 0 &&nums[i]==1){
                    cout<<i<<" "<<n+1<<" ";
                    flag = true;
                    continue;
                }
                cout<<i<<" ";
                
            }
            cout<<endl;
        }
    }
    return 0;
}  
