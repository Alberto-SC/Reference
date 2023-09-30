#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

solve(vector<int> a,bool swap,int l,int r){
    for(int i = 0;i)
}

signed main(){__
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    int ans = -1;
    vector<int> mx(n);
    mx[n-1] = nums[n-1];
    for(int i = n-2;i>=0;i--)
        mx[i] = max(mx[i+1],nums[i]);
    
    int x =-1;
    for(int j = k-1;j>=0;j--){
        if(mx[k]>nums[j]){x = j;break;}
    }
    if(x ==-1)return cout<<-1<<endl,0;
    ans=(k-1)-x;
    for(int i = k;i<n;i++){
        if(nums[i]>nums[x]){
            ans  += i-(k-1);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}