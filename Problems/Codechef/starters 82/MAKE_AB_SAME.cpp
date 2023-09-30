#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        int one = 0;
        for(auto &c:a)cin>>c,one+=c==1;
        for(auto &c:b)cin>>c; 
        bool flag = true;
        if(a[0]!= b[0] || a[n-1]!=b[n-1])flag = false;
        for(int i = 1;i<n-1;i++){
            if(a[i]== 0 && b[i]==1 && !one)flag = false;
            if(a[i]== 1 && b[i]==0)flag = false;

        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

 

