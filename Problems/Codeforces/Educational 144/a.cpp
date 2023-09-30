#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';
#define int long long
using namespace std;


signed main(){__
    int T,n;
    cin>>T;
    string S;
    for(int i = 1;i<=3000;i++){
        if(i%3 ==0)S+="F";
        if(i%5==0)S+="B";
    }
    while(T--){
        cin>>n;
        string s;
        cin>>s;

        bool f = false;
        for(int i = 0;i<S.size();i++){
            bool flag = true;
            for(int j = 0;j<n;j++){
                if(i+j>=S.size()){
                    flag = false;
                    break;
                }
                if(S[i+j]!=s[j])flag = false;
            }
            if(flag){
                f = true;
                break;
            }
        }
        if(f){cout<<"YES"<<endl;}
        else cout<<"NO"<<endl;
    }
    return 0;
}

