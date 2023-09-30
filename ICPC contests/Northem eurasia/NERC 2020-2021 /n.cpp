#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,c1,c2,c3;
    cin>>t;
    while(t--){
        cin>>c1>>c2>>c3;
        vector<int> nums(5);
        for(auto &c:nums)cin>>c;
        c1-=nums[0];
        c2-=nums[1];
        c3-=nums[2];
        if(c1<0 || c2<0 || c3<0){
            cout<<"NO"<<endl;
            continue;   
        }
        nums[3] -= min(nums[3],c1);
        if(nums[3])
            c3-=nums[3];
        if(c3<0){
            cout<<"NO"<<endl;
            continue;
        }

        nums[4] -= min(nums[4],c2);
        if(nums[4])
            c3-=nums[4];
        if(c3<0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;


    }
    return 0;
}  

