#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    string s;
    cin>>s;
    n = s.size();
    int l = 0,r;
    for(int i = 0;i<n;i++){
        if(s[i]=='U'){
            l = i;
            break;
        }
    }
    for(int i = n-1;i>=0;i--){
        if(s[i]=='F'){
            r = i;
            break;
        }
    }
    for(int i = 0;i<l;i++)
        s[i] ='-';
    for(int i = n-1;i>r;i--)
        s[i] ='-';
    for(int i = l+1;i<r;i++)
        s[i] ='C';
    cout<<s<<endl;
}   