#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int mp[640][200007];
signed main(){__
    int T = 1,n;
    cin>>T;

    while(T--){
        cin>>n;
        vector<int> a(n),b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
    
        int lim = sqrt(2*n);
        for(int i = 0;i<n;i++)
            if(a[i]<=lim)mp[a[i]][b[i]]++;

        long long ans = 0;
        vector<int> calc(n+1);

        for(int i = 0;i<n;i++){
            if(a[i]<=lim){
                int x = a[i]*a[i];
                int need = x-b[i];
                if(need>n || need<0)continue;
                ans+=mp[a[i]][need];
            }
        }
        for(int i = 2;i<=lim;i+=2)
            ans-=mp[i][i*i/2];

        ans/=2;
        for(int i = 0;i<n;i++){
            for(int y = 1;y<=lim && y<a[i]; y++){
                int x = y*a[i];
                int need = x-b[i];
                if(need>n || need<0 || x>2*n)continue;
                ans+=mp[y][need];
            }
        }

        for(int i = 0;i<n;i++)
            if(a[i]<=lim)mp[a[i]][b[i]]--;

        cout<<ans<<endl;
    }
    return 0;
}