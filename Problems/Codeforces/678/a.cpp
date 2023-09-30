#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+= nums[i];
        }
        if(sum == m)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

