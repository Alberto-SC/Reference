#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,a,b,c;
    cin>>T;
    while(T--){
        cin>>x;
        vector<int> v(4);
        cin>>v[1]>>v[2]>>v[3];
        bool flag = true;
        for(int i= 1;i<=3;i++){
            if(v[i]==0  && x ==i)flag = false;
            if(v[i]== i)flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}