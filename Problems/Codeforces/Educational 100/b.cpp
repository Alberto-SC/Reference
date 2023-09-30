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
        vector<int> b(n);
        lli one= 0,two = 0,sum = 0;
        for(int i = 0;i<n;i++){
            if(i&1)one+=nums[i]-1;
            else two+=nums[i]-1;
            sum+=nums[i];
        }
        // cout<<one<<" "<<two<<endl;
        if(one*2<=sum){
            for(int i = 0;i<n;i++){
                if(i&1)cout<<1<<" ";
                else cout<<nums[i]<<" ";
            }
        }
        else{
            for(int i = 0;i<n;i++){
                if(i&1)cout<<nums[i]<<" ";
                else cout<<"1 ";
            }
        }
        cout<<endl;
    }
    return 0;
}  

