#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

int32_t main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        bool flag = true;
        for(int i = 0;i<n-1;i++){
            if(a[i]>a.back())swap(a[i],b[i]);

            if(b[i]>b.back())swap(a[i],b[i]);

            if(a[i]>a.back() || b[i]>b.back())flag = false;
        }

        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
