#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
signed main(){__
    int t,n;
    vector<int> even;
    int l1 = 0,l2 = 1,c;
    for(int i = 0;i<120;i++){
        if(__builtin_saddll_overflow(l1,l2,&c)){
            break;
        }
        if(c%2==0)even.push_back(c);
        l1 = l2;
        l2 = c;
    }
    cin>>t;
    while(t--){
        cin>>n;
        int idx = 0,sum = 0;
        while(idx <even.size() && even[idx]<n){
            sum+=even[idx++];
        }
        cout<<sum<<endl;
    }
    return 0;
}
