#include <bits/stdc++.h>
#include <cmath>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;


signed main(){__
    int T,n;
    cin>>T;
    vector<int> v;
    for(int i = 2;i<=2000000;i++){
        int x = i*i*i;
        int y = sqrt(x);
        v.push_back(y-i);
        
    }

    while(T--){
        cin>>n;
        if(n == 1){
            cout<<4<<endl;
            continue;
        }
        int idx = lower_bound(v.begin(),v.end(),n)-v.begin();    
        int p3  = idx+1;
        int need = n-v[idx-1];
        int ans = 0;
        if(need == 1)ans = sqrt(p3*p3*p3);
        else ans= sqrt(p3*p3*p3)+need;

        if(ans*ans == p3*p3*p3)ans++;
        cout<<ans*ans<<endl;

        
    }
}
