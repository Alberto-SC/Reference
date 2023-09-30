#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s,t;
        cin>>n;
        cin>>s>>t;
        int last = -1;
        int x = 0;
        bool flag = true;
        for(int i= 0;i<n;i++){
            if(s[i]=='W'|| t[i]=='W'){
                if(last ==-1){
                    last = i;
                    continue;
                }
                else{
                    int len = i-last-1;
                    if(len&1){
                        if(s[last]==s[i])flag = false;
                    }
                    else{
                        if(s[last]!=s[i])flag = false;
                    }
                }
                last = i;
            }
        }
        if(flag)cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }
    return 0;
}