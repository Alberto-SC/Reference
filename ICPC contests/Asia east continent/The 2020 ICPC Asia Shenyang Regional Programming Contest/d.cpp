#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    for(int i = 2;i<=9;i++){
        vector<int> valid;
        int mx = 0;
        cout<<"N: "<<i<<endl;
        map<int,vector<int>> mp;
        for(int mask = 0;mask<(1<<i);mask++){
            int ans = 0;
            for(int j = 0;j<i;j++){
                int cont = 0;
                for(int k = j;k<i;k++){
                    cont+=((mask>>k)&1);
                    if(cont&1)ans++;
                }
            }    
            mp[ans].push_back(mask);
            if(ans == mx){
                valid.push_back(mask);
            }
            else if(ans >mx){
                valid.clear();
                mx = ans;
            }
        }
        cout<<"MX: "<<mx<<endl;
        for(auto c:mp[mx]){
            bitset<10> bs(c);
            cout<<bs<<" "<<c<<endl;
        }

    }
    return 0;
}