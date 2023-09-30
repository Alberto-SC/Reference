#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


string get(string s,int l,int r){
    for(int i = l;i<=(l+r)/2;i++){
        swap(s[i],s[r-(i-l)]);
    }
    for(int i= l;i<=r;i++){
        if(s[i]=='d')s[i] = 'p';
        else s[i] = 'd';
    }
    return s;
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int l = 0;
        for(int i= 0;i<n;i++){
            if(s[i]== 'p'){
                l = i;
                break;
            }
        }
        string ans = s;
        for(int i =l ;i<n;i++){
            ans = min(ans,get(s,l,i));
        }
        cout<<ans<<endl;
    }
    return 0;
}