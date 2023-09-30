#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int l = 0,r = n-1;
        while(l<r){
            if(s[l]!=s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }
        cout<<n-(l*2)<<endl;
    }
    return 0;
}