#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        set<int> x;
        set<int> y;
        x.insert(x1);
        x.insert(x2);
        x.insert(x3);
        y.insert(y1);
        y.insert(y2);
        y.insert(y3);
        if(x.size()==2 && y.size()==2)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}