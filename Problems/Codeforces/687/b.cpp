#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = n+1;
        for(int i = 1;i<=100;i++){
            int cont = 0;
            for(int j = 0;j<n;){
                if(nums[j]!= i){
                    j+=k;
                    cont++;
                }
                else j++;
            }
            ans = min(ans,cont);
        }
        cout<<ans<<endl;
    }
    return 0;
}  

