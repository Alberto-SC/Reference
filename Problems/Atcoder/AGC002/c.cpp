#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n,l;
    cin>>n>>l;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    int x =-1,y = -1;
    for(int i = 1;i<n;i++){
        if((nums[i]+nums[i-1])>=l)x = i-1,y = i;
    }
    if(x ==-1 && y==-1)cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        for(int i = 1;i<=x;i++)
            cout<<i<<endl;
        for(int i = n-1;i>y;i--)
            cout<<i<<endl;
        cout<<y<<endl;
    }
    return 0;
}