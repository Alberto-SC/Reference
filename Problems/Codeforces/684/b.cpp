#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n*k);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int first = (n*k)-1;
        first-= n/2;
        lli sum = 0;
        // cout<<first<<endl<<endl;
        int cont = 0;
        for(int i = first;i>=0;i-=(n/2)+1){
            cont++;
            // cout<<i<<endl;
            sum+=nums[i];
            if(cont==k)break;
        }
        cout<<sum<<endl;
    }
    return 0;
}  
