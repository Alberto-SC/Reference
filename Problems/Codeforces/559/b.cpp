#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
int main(){__
	lli t= 1,n;
    while(t--){
        cin>>n;
        vector<pair<lli,lli>> nums(n);
        for(lli i = 0;i<n;i++){
            cin>>nums[i].x;
            nums[i].y = i;
        }
        sort(nums.begin(),nums.end());
        lli l = 0,r = 1e9+7;
        while(l+1<r){
            lli m = (l+r)>>1;
            bool flag = true;
            lli mn = nums[n-1].y;
            lli mx = nums[n-1].y;
            for(lli i = n-2;i>=0;i--){
                if(abs(nums[i].y-mn)>abs(nums[i].y-mx)){
                    if(m * abs(nums[i].y-mn)> nums[i].x)flag = false;
                }
                else {
                    if(m * abs(nums[i].y-mx)> nums[i].x)flag = false;
                }
                mn = min(mn,nums[i].y);
                mx = max(mx,nums[i].y);
            }
            if(flag)
                l = m;
            else 
                r = m;

        }
        cout<<l<<endl;
    }
    return 0;
}  

