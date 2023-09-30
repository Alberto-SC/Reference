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
        vector<lli> nums(n);
        lli sump = 0,sumi = 0;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            if(i&1)sumi+=nums[i];
            else sump+= nums[i];
        }
        if(sump == sumi){
            cout<<"YES"<<endl;
            continue;
        }
        lli sumpO = sump,sumiO = sumi;
        bool flag = false;
        for(int i = 0;i<n-1;i++){
            if(i&1){
                sumi-=nums[i];
                sumi+=nums[i+1];
                sump-=nums[i+1];
                sump+=nums[i];
            }   
            else{
                sump-=nums[i];
                sump+=nums[i+1];
                sumi-=nums[i+1];
                sumi+=nums[i];
            }
            if(sumi == sump){
                flag = true;
                swap(nums[i],nums[i+1]);
                break;
            }
            else{
                sumi = sumiO;
                sump = sumpO;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}  
