#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
vector<int> acx(maxn);
vector<int> acy(maxn);

int n,x,y,rx,ry;
bool check(int m){
    int x0 = 0,y0;
    for(int i = 0;i<(n-m)+1;i++){
        x0 = rx-(acx[i+(m-1)]-(i?acx[i-1]:0));
        y0 = ry-(acy[i+(m-1)]-(i?acy[i-1]:0));
        // cout<<x0<<" "<<y0<<" "<<i<<" "<<abs(x0-x)+abs(y0-y)<<endl;
        int dx = abs(x0-x);
        int dy = abs(y0-y);
        if((dx+dy)==m||(abs(m-(dx+dy))%2==0 && (dx+dy)<m))return true;
    }
    return false;
}

signed main(){__
    cin>>n;
    string s;
    cin>>s;
    cin>>x>>y;
    for(int i = 0;i<n;i++){
        if(s[i]=='U'){
            acy[i] = 1+(i?acy[i-1]:0);
            acx[i] = i?acx[i-1]:0;
            ry++;
        }
        else if(s[i]== 'D'){
            acy[i] = -1+(i?acy[i-1]:0);
            acx[i] = i?acx[i-1]:0;
            ry--;
        }
        else if(s[i]== 'R'){
            acx[i] = 1+(i?acx[i-1]:0);
            acy[i] = i?acy[i-1]:0;
            rx++;
        }
        else if(s[i]== 'L'){
            acx[i] = -1+(i?acx[i-1]:0);
            acy[i] = i?acy[i-1]:0;
            rx--;
        }
    }
    int l = -1,r = n+1;
    // for(int i = 0;i<=n;i++){
        // cout<<i<<" "<<check(i)<<endl;
//    }
    while(l+1<r){
        int m = (l+r)>>1;
        if(check(m))
            r = m;
        else 
            l = m;
    }
    if(r ==n+1)cout<<-1<<endl;
    else cout<<r<<endl;
    return 0;
}  
