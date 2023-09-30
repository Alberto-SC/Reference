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
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        vector<int> b(n);
        for(auto &c:b)cin>>c;
        vector<int> dmn(n);  
        vector<int> dmx(n);
        int l = 0;
        for(int i = 0;i<n;i++){
            dmn[i] = *lower_bound(b.begin(),b.end(),a[i])-a[i];
        }   
        int r = 0;
        vector<pair<int,int>> As(n);
        for(int i = 0;i<n;i++){
            As[i].first = a[i];
            As[i].second = i;
        }
        sort(As.begin(),As.end());
        vector<int> v(n);
        for(int i= 1;i<n;i++){
            if(As[i].first>b[i-1])v[i] = 1;
        }
        vector<int> nxt(n);
        int last = n;
        for(int i = n-1;i>=0;i--){
            nxt[i] = last;
            if(v[i] == 1)last =i;
        }
        for(int i = 0;i<n;i++){
            int x = b[nxt[i]-1];
            dmx[As[i].second] = x-As[i].first;
        }

        for(auto c:dmn)cout<<c<<" ";
        cout<<endl;
        for(auto c:dmx)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}