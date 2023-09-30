#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,p,w,d;
    while(t--){
        cin>>n>>p>>w>>d;
        if(n*w<p)return cout<<-1<<endl,0;
        lli f = p/w;
        lli res = p-(f*w);
        if(res==0)return cout<<f<<" "<<0<<" "<<n-f<<endl,0;
        lli m = res%d;
        // cout<<m<<endl;
        if(m == 0){
            // cout<<res/d<<" "<<f<<endl;
            if(f+(res/d)<=n){
                return cout<<f<<" "<<res/d<<" "<<n-(f+res/d)<<endl,0;
            }
        }
        lli y = w%d;   
        lli need = d-m;
        // cout<<res<<endl;
        // cout<<y<<" "<<need<<endl;
        vector<bool>ress(d+1);
        lli aux = y;
        int x = 1;
        while(1){  
            if(y == need){break;}
            else if(ress[y]== true){break;}
            else ress[y] = true;
            (y+=aux)%=d;
            x++;
            if(x==f)break;
        }
        if(y == need){
            lli z = p-((f-x)*w);
            if(f-x<0)return cout<<-1<<endl,0;
            cout<<f-x<<" "<<z/d<<" "<<n-(f-x)-(z/d)<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

