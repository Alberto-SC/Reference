#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int p1 = 1e9+9, p2 = 1e9+7;
signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int idx,mn= 1e15;
        for(int i = 0;i<n;i++){
            if(nums[i]<mn){
                mn = nums[i];
                idx = i;
            }
        }
        int mx = 2e9;
        cout<<n-1<<endl;
        int turn = 0;
        for(int i = 0;i<n;i++){
            if(i==idx)continue;
            if(turn)
                cout<<idx+1<<" "<<i+1<<" "<<mn<<" "<<p1<<endl;
            else
                cout<<idx+1<<" "<<i+1<<" "<<mn<<" "<<p2<<endl;
            turn^=1;
        }
    }
    return 0;
}  
