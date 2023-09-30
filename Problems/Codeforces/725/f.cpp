#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,l,r;
    cin>>T;
    map<int,int> mp;
    int x = 1;
    for(int i = 1;i<=10;i++){
        mp[x] = i;
        x*=10;
    }
    while(T--){
        cin>>l>>r;
        int pw = 1;
        while(pw<=r){
            pw*=10;
        }
        pw/=10;
        int aux = pw;

        int ans = 0;
        int ac = 0;
        while(pw){
            ans+=((r/pw)-ac)*mp[pw];
            ac+=((r/pw)-ac);
            pw/=10;
        }

        int ans2 = 0;
        pw = aux;
        ac = 0;
        while(pw){
            ans2+=((l/pw)-ac)*mp[pw];
            ac+=(l/pw)-ac;
            pw/=10;
        }
        cout<<ans-ans2<<endl;
    }
    return 0;
}