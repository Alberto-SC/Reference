#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int o= 0,z =0;
        vector<int> nums(n);
        for(auto &c:nums){
            cin>>c;
            o+=c==1;
            z+=c==0;
        }
        if(n&1){
            cout<<-1<<endl;
            continue;
        }
        int need = n/2;
        if(o>need){
            if((o-need)%2 == 0){
                cout<<(o-need)/2<<endl;
            }
            else{
                int x = need-1;
                if(x)cout<<(((o-need)+1)/2)+1<<endl;
                else cout<<-1<<endl;
            }
        }
        else if(o>=1){
            cout<<need-o<<endl;
        }
        else cout<<-1<<endl;

    }
    return 0;
}

