#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
    vector<int> all_;
    for(int i = 100;i<=999;i++){
        for(int j = 100;j<=999;j++){
            int x = i*j;
            string a = to_string(x);
            string b = a;
            reverse(b.begin(),b.end());
            if(a==b)
                all_.push_back(x);
        }
    }
    sort(all_.begin(),all_.end());
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int idx = lower_bound(all_.begin(),all_.end(),n)-all_.begin();
        cout<<all_[idx-1]<<endl;
    }

    return 0;
}
