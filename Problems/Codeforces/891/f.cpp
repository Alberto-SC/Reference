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
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;

        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            if(x>0){
                int l = -1e9,r = (x/2)+1;
                while(l+1<r){
                    int m = (l+r)>>1;
                    if(m*(x-m)<=y)l = m;
                    else r = m;
                }
                
                if(l*(x-l)==y){
                    if(l == x-l){
                        cout<<(mp[l]*(mp[l]-1))/2<<" ";
                    }
                    else
                        cout<<mp[l]*mp[x-l]<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            else{
                int l = (x/2)-1,r = 1e9;
                while(l+1<r){
                    int m = (l+r)>>1;
                    if(m*(x-m)<=y)r = m;
                    else l = m;
                }
                if(r*(x-r)==y){
                    if(r == x-r){
                        cout<<(mp[r]*(mp[r]-1))/2<<" ";
                    }
                    else
                        cout<<mp[r]*mp[x-r]<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
        }
        cout<<endl;
    
    }
    return 0;
}