#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    while(T--){
        cin>>n>>x;
        vector<int> nums(n);
        vector<int> f(500007);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            f[nums[i]]++;
        }
        for(int i= 1;i<n;i++){
            int x = f[i]/(i+1);
            int y = f[i]%(i+1);
            f[i] = y;
            f[i+1]+=x; 
        }
        bool flag = true;
        for(int i = 0;i<x;i++){
            if(f[i])flag = false;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}