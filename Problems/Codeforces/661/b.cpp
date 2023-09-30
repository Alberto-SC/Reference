#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n),b(n);
        int mna = 1000000007, mnb = mna;
        for(auto &c:a)cin>>c,mna = min(mna,c);
        for(auto &c:b)cin>>c,mnb = min(mnb,c);
        lli ans = 0;
        for(int i = 0;i<n;i++){
            int x =  min(a[i]-mna,b[i]-mnb);
            ans+=x;
            a[i]-=x;
            b[i]-=x;
            ans+=a[i]-mna;
            ans+=b[i]-mnb;
        }
        cout<<ans<<endl;
    }
    return 0;
}

