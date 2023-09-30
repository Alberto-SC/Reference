#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);



signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n-1);
    int x = 1;
    vector<int> ans;
    for(int i= 1;i<n-1;i++){
        if(__gcd(i,n)==1){
            (x*=i)%=n;
            ans.push_back(i);
        }
    }
    (x*=n-1)%=n;
    if(x==1)ans.push_back(n-1);
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}  
