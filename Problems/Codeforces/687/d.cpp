#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    vector<int> bits(31);
    for(auto &c:nums)cin>>c;
    for(int i = 1;i<n;i++)
        for(int j = 31;j>=0;j--)
            if((nums[i]>>j)&1){bits[j]++;break;}
    for(int i = 0;i<31;i++)
        if(bits[i]>2)return cout<<1<<endl,0;
    int ans = n+1;
    for(int i = 0;i<n;i++){
        int x = nums[i];
        for(int j = i+1;j<n;j++){
            x^=nums[j];
            if((i && x<nums[i-1]) || (j<n-1 && x>nums[j+1]))
                ans = min(ans,j-i);
            if(j+2<n){
                int z = nums[j+1];
                for(int k = j+2;k<n;k++){
                    z^=nums[k];
                    if(x>z)
                        ans = min(ans,j-i+k-(j+1));
                }
            }
            if(i-2>=0){
                int z = nums[i-1];
                for(int k = i-2;k>=0;k--){
                    z^=nums[k];
                    if(x<z)
                        ans = min(ans,j-i+(i-1)-k);
                }
            }
        }
    }
    if(ans == n+1)cout<<-1<<endl;
    else
    cout<<ans<<endl;
    return 0;
}  

