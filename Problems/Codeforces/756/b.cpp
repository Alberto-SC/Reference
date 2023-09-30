#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b;
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(a*3<=b)cout<<a<<endl;
        else{
            int x= a/2;
            int diff = b-(x*2);
            if(a&1){
                if(diff>=3)
                x++;
                diff-=3;
            }
            x+=diff/4;
            cout<<x<<endl;
        }
    }
    return 0;
}