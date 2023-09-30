#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

using namespace std;
signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;

        vector<int> ac(n+1);
        vector<int> pref(n);
        pref[0] = b[0];
        for(int i= 1;i<n;i++)
            pref[i] = pref[i-1]+b[i];
        
        vector<int> ans(n);
        
        for(int i = 0;i<n;i++){
            int l = i-1,r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                int sum = pref[m]-(i?pref[i-1]:0);
                if(sum<=a[i])l = m;
                else r = m;
            }
            if(l>=i){
                ac[i]++;
                ac[l+1]--;
                int sum = pref[l]-(i?pref[i-1]:0);
                if(r<n)
                    ans[r] +=  a[i]-sum;
            }
            else{
                ans[r] += a[i];
            }
        }
        
        for(int i = 1;i<n;i++)
            ac[i]+=ac[i-1];

        for(int i = 0;i<n;i++)
            ans[i]+=b[i]*ac[i];


        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
