#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        vector<int> ans;
        vector<int> b(n+1);
        for(int i = 0;i<2*n;i++){
            if(b[nums[i]])continue;
            else ans.push_back(nums[i]),b[nums[i]]++;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}