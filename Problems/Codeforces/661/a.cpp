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
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int cont = 0;
        for(int i = 0;i<n-1;i++){
            if(nums[i+1]-nums[i]>1)cont++;
        }
        if(cont)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

