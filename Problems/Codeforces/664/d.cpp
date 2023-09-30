    #define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli n,m,d;
    cin>>n>>d>>m;
    vector<lli> a(n);
    for(auto &c:a)cin>>c;
    sort(a.rbegin(),a.rend());
    vector<lli> ac(n+1);
    ac[0] = 0;
    for(lli i = 1;i<=n;i++)  
        ac[i] = ac[i-1]+a[i-1];
    lli cont = 0;
    lli ans = 0;    
    ans+=a[0];
    for(lli i = 1;i<n;i++){
        if(a[i]<=m)break;
        if(n-(cont*d)-1<0 || n-(cont*d)-d <0)break;
        if(ac[n-(cont*d)]-ac[n-(cont*d)-d]> a[i])break;
        ans+=a[i];
        cont++;
    }
    lli mm = 0;
    for(lli i = n-(cont*d)-1;i>cont;i--){
        if(a[i]<=m && mm ==0){
           ans+=a[i];
        }
        else{
            if(mm == 0)
                mm = d;
            else 
                mm--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

