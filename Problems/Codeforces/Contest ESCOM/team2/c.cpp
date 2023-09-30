#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        set<pair<lli,lli>> nums;
        lli c;
        for(lli i = 0;i<n;i++){
            cin>>c;
            nums.insert({c,i});
        }
        lli index = n;
        lli ans = 0;
        for(lli i = 0;i<=n-2;i++){
            lli n1,n2;
            n1 = (*nums.begin()).first;
            nums.erase(nums.begin());
            n2 = (*nums.begin()).first;
            nums.erase(nums.begin());
            ans+=n1+n2;
            nums.insert({n1+n2,index++});
        }
        cout<<ans<<endl;
    }
    return 0;
}