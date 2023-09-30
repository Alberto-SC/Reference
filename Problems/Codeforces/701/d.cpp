#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
lli lcm(vector<lli> & nums){
    lli ans = 1; 
    for(lli & num : nums) ans = lcm(ans, num);
    return ans;
}
int main(){__
	int t= 1,n,m;
    vector<lli> nums(16);
    for(int i = 0;i<16;i++)
        nums[i] = i+1;
    lli L = lcm(nums);
    cin>>n>>m;
    int M[n][m];
    int ans[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if((i+j)&1){
                ans[i][j] = L;
            }
            else{
                ans[i][j] = L+pow(M[i][j],4);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  

