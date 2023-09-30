#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        int diff0 = 0,diffmn = 1e9,diffmx = 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(a[i]<b[i])flag = false;
            if(b[i]== 0)diff0 = max(diff0,a[i]-b[i]);
            else{
                diffmn = min(diffmn,a[i]-b[i]);
                diffmx = max(diffmx,a[i]-b[i]);
            }
        }
        if(diffmn !=diffmx && diffmn !=1e9)flag = false;
        else if(diff0>diffmn ) flag = false;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
