#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){ 
        int r = 0,g =0 ,b =0;
        string s;
        cin>>s;
        bool flag = true;
        for(int i = 0;i<s.size();i++){
            if(s[i]== 'r')r++;
            if(s[i]== 'g')g++;
            if(s[i]== 'b')b++;
            if(s[i]== 'R' && !r)flag = false;
            if(s[i]== 'G' && !g)flag = false;
            if(s[i]== 'B' && !b)flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}