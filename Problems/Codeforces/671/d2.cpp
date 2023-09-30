#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli gauss(lli n){
    return (n*(n+1))/2;
}
int main(){__
    lli t = 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    vector<int> ans(n);

    int cont = 0;
    for(int i = 1;i<n;i+=2)
        ans[i] = nums[cont++];
    for(int i = 0;i<n;i+=2)
        ans[i] = nums[cont++];
    int res =0;
    for(int i = 1;i<n-1;i++){
        if(ans[i]<ans[i+1] && ans[i]<ans[i-1])res++;
    }
    cout<<res<<endl;
    for(auto c:ans)
        cout<<c<<" ";
    cout<<endl;
    return 0;
}

