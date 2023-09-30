#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

pair<bool,bool> check(int idx,string &s){
    int n = s.size();
    bool winA = false;
    bool winB = false;
    for(int i = max(0ll,idx-2);i<=idx+1;i++){
        if(i+2>=n)continue;
        int cont = s[i]=='X';
        cont += s[i+1]=='X';
        cont += s[i+2]=='X';
        if(cont == 3)winA = true;
        cont = 0;
        cont = s[i]=='O';
        cont += s[i+1]=='O';
        cont += s[i+2]=='O';
        if(cont == 3)winB = true;

    }
    return {winA,winB};
}

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;

        n = s.size();
        int ans = 2;

        bool alice = false,tie = false;
        for(int i = 0;i<n-1;i++){
            swap(s[i],s[i+1]);
            auto x = check(i,s);
            /* cout<<x.first <<" "<<x.second<<endl; */
            if(x.first){
                alice = true;
                break;
            }
            bool bob = false;
            bool alice2 = true;
            /* cout<<"BOB turn"<<endl; */
            for(int j = 0;j<n-1;j++){
                swap(s[j],s[j+1]);
                auto y = check(j,s);
                /* cout<<y.first<<" "<<y.second<<endl;  */
                if(y.second){
                    bob = true;
                    alice2 = false;
                    swap(s[j],s[j+1]);
                    break;
                }
                if(!y.first)alice2 = false;

                swap(s[j],s[j+1]);
            }
            /* cout<<"END "<<bob<<" "<<alice2<<endl; */
            if(alice2){
                alice = true;
                break;
            }
            tie |= !bob;
            swap(s[i],s[i+1]);
        }
        if(alice)cout<<"Alice"<<endl;
        else if(tie)cout<<"Tie"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}

