#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<lli> a(n);
        vector<lli> b(m);
        lli suma =0,sumb= 0;
        for(auto &c:a)cin>>c,suma+=c;
        for(auto &c:b)cin>>c,sumb+=c;
        set<lli> sa(a.begin(),a.end());
        set<lli> sb(b.begin(),b.end());
        if(*(--sa.end())>*(sb.begin()))return cout<<-1<<endl,0;
        bool flag = false;
        for(lli i = 0;i<n;i++){
            if(sb.count(a[i])){
                cout<<sumb+(suma*m)-(a[i]*m)<<endl;
                flag = true;
                break;
            }
        }
        if(flag)continue;
        lli ans = sumb;
        lli mx = -1,idx;
        for(lli i = 0;i<n;i++){
            if(a[i]>mx){
                mx = a[i];
                idx = i;
            }
        }
        suma-=a[idx];
        lli mx2 = -1;
        for(lli i = 0;i<n;i++){
            if(a[i]> mx2 && i != idx){
                mx2 = a[i];
            }
        }
        ans+=suma*m;
        ans-=mx2;
        ans+=a[idx];
        cout<<ans<<endl;
    }
    return 0;
}  

