#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,q,k,l,r;
    while(t--){
        cin>>n>>q>>k;
        vector<lli> nums(n+1,0);
        vector<lli> pref(n+1);
        for(lli i = 1;i<=n;i++){
            cin>>nums[i];
        }
        for(lli i = 1;i<n;i++){
            pref[i]= pref[i-1]+((nums[i]-nums[i-1])-1)+((nums[i+1]-nums[i])-1);
        }
        pref[n] = pref[n-1]+(k-nums[n])+((nums[n]-nums[n-1])-1);
        for(lli i = 0;i<q;i++){
            cin>>l>>r;
            if(l == r){
                cout<<k-1<<endl;
                continue;
            }
                
            lli ac = pref[r-1]-pref[l];
            ac+=nums[l]-1;
            if(l+1<=n){
                ac+= (nums[l+1]-nums[l])-1;
            }
            ac+=k-nums[r];
            if(r-1>=1){
                ac+=(nums[r]-nums[r-1])-1;
            }
            cout<<ac<<endl;
        }
    }
    return 0;
}  

