#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        int k = n;
        int mx = 0;
        map<int,int> f;
        for(int i = 2;i*i<=n;i++){
            while((n%i)==0){
                f[i]++;
                mx = max(mx,i);
                n/=i;
            }
        }
        if(n>1)
            f[n]++;
        int l = 1,r = k;
        while(l+1<r){
            int m = (l+r)>>1;
            bool flag = true;
            for(auto c:f){
                int pw = 0;
                int x= c.first;
                while(1){
                    pw+=m/x;
                    if(m/x==0)break;
                    x*=c.first;
                }
                if(pw<c.second)flag = false;
            }
            if(flag)r = m;
            else l = m;
        }
        cout<<r<<endl;
    }
    return 0;
}