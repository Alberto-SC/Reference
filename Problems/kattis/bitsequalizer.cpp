#include <bits/stdc++.h>
using namespace std; 
int main(){
    int q;
    cin>>q;
    string s,t;
    int z,u,sz,su;
    int k = 1;
    while(q--){
        cin>>s>>t;
        z = u = sz = su = 0;
        int n = s.size(),ans = 0;
        for(int i = 0;i<n;i++){
            if(t[i]-'0')u++;
            else z++;
            if(s[i]-'0' == 1)su++;
            else if(s[i]-'0' == 0)sz++;
        }
        for(int i = 0;i<n;i++){
            if(s[i] == '?'){
                ans++;
                if(su<u&& t[i] == '1'){s[i] = '1';su++;}
                else{s[i] = '0';sz++;}
            }
        }
        int diff = 0;
        cout<<"Case "<<k<<": ";
        if(z>sz)cout<<-1<<endl;
        else{
            for(int i = 0;i<n;i++){
                if(s[i] == '0' && su<u && t[i]=='1'){s[i] = '1';su++;ans++;}
            }
            for(int i = 0;i<n;i++)
                if(s[i]!=t[i])diff++;
            cout<<ans+(diff/2)<<endl;
        }
        k++;
    }
    return 0;
}