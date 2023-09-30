#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,k;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        vector<int> nums(m);
        for(auto &c:nums)cin>>c;
        int x = n/k,y = x+1;
        int cy = n-(k*x);
        bool flag = true;
        for(int i = 0;i<m;i++){
            if(nums[i]== y)cy--;
            else if(nums[i]>y)flag = false;
        }
        if(cy<0)flag = false;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}   