#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x1,x2,x3,x4;
    cin>>T;
    while(T--){
        cin>>x1>>x2>>x3>>x4;
        bool flag = false;
        int cont = 4;
        while(cont--){
            if(x1<x2 && x3<x4 && x1<x3 && x2<x4)flag = true;
            int y1 = x1,y2 = x2,y3 = x3,y4 = x4;
            x2 = y1;
            x4 = y2;
            x3 = y4;
            x1 = y3;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}