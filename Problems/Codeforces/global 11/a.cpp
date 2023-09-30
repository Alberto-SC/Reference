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
        int sn = 0,sp = 0;
        for(auto &c:nums)cin>>c,c<=0?sn+=c:sp+=c;
        bool flag = true;
        if(abs(sn)>sp)
            sort(nums.begin(),nums.end());
        else if(sp>abs(sn))
            sort(nums.rbegin(),nums.rend());
        else if(abs(sn) == sp){
            cout<<"NO"<<endl;
            flag = false;
        }
        if(flag){
            cout<<"YES"<<endl;
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}

