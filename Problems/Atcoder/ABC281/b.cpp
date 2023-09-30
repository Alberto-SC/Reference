#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        bool flag = true;
        if(n!=8)flag = false;
        if(!isupper(s[0]))flag = false;
        for(int i = 0;i<6;i++){
            if(!isdigit(s[i+1]))flag = false;
            else if(s[i+1] == '0' && i == 0)flag = false;
        }
        if(!isupper(s[n-1]))flag = false;
    
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}