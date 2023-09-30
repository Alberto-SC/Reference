#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int lcm(int a,int b){
    return a*b/__gcd(a,b);
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n+2,1);
        for(int i = 1;i<=n;i++)cin>>nums[i];
        bool flag = true;
        vector<int> b(n+2,1);
        for(int i=1;i<=n+1;i++){
            b[i]=lcm(nums[i],nums[i-1]);
        }
        for(int i=1;i<=n;i++){
            if(__gcd(b[i],b[i+1])!=nums[i]){
                flag = false;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}