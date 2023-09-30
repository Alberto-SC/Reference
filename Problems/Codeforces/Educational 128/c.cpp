#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int O,Z;
bool check(int x,string &s){
    int n = s.size();
    int l = 0,r = 0;
    int o = 0,z = 0;
    while(r<n){
        o+=s[r]=='1';
        z+=s[r]=='0';
        r++;
        while(l<n && z>x){
            o-=s[l]=='1';
            z-=s[l]=='0';
            l++;
        }
        if(O-o<=x)return true;
    }
    return false;
}

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        O = 0,Z = 0;
        for(int i = 0;i<n;i++){
            O+=s[i] == '1';
            Z+=s[i] == '0';
        }
        int l = -1,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,s))
                r = m;
            else 
                l = m;
        }
        cout<<r<<endl;
    }
}
