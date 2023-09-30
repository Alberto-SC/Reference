#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        cout<<n<<endl;
        for(int i = n-1;i>0;i--){
            for(auto c:v)cout<<c<<" ";
            cout<<endl;
            swap(v[i],v[i-1]);
        }
        for(auto c:v)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}