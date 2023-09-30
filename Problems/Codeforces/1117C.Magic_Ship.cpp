#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> px;
vector<int> py;

int n,a,b,c,d;
bool check(int m){
    int x,y,z = m/n;
    x = c +(px.back()-c)*z;
    y = d +(py.back()-d)*z;
    if(m%n){
        x+=px[(m%n)-1]-c;
        y+=py[(m%n)-1]-d; 
    }
    int dis = abs(x-a)+abs(y-b);
    if(abs(x-a)+abs(y-b)<=m)return true;
    return false;
}

signed main(){
    cin>>c>>d>>a>>b;
    cin>>n;
    px.resize(n);
    py.resize(n);
    int x = c;
    int y = d;
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        if(s[i]=='D')y--;
        if(s[i]=='U')y++;
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        px[i] = x;
        py[i] = y;

    }
    int l = 0,r = 1e18;
    while(l+1<r){
        int m = (l+r)>>1;
        if(check(m))
            r = m;
        else 
            l = m;
    }
    if(r == 1e18)
        return cout<<-1<<endl,0;
    cout<<r<<endl;
    return 0;
}