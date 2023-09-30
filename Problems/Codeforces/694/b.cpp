#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        lli sum = 0;
        lli mn = 1e9+7;
        vector<lli> copy = nums;
        bool flag = true;
        while(flag){
            for(int i = 0;i<n;i++){
                if(!flag){
                    copy[i] = 0;
                }
                if(copy[i]%x ==0)
                    copy[i] = copy[i]/x,sum+=nums[i];
                else{
                    flag = false;
                    sum+=nums[i];
                    copy[i] = 0;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(copy[i])sum+=nums[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}  

