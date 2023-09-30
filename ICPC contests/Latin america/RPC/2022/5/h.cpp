#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


bool isvowel(char c){
     if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c== 'y')return true;
     return false;
}

signed main(){__
    int t,n,id = 1;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int pos = -1,pos2 = -1;
        bool flag = true;        
        for(int i = 0;i<n;i++){
            if(s[i]== '?')continue;
            if(isvowel(s[i])){
                if(pos==-1)pos = i;
                else if(pos%2 != i%2)flag = false;
            }
            else {
                if(pos2==-1)pos2 = i;
                else if(pos2%2 != i%2)flag = false;
            }
        }
        if(pos!= -1 && pos2!= -1 && (pos&1) == (pos2&1))flag = false;
        if(!flag){
            cout<<"String #"<<id<<": 0"<<endl;
            id++;
            cout<<endl;
            continue;
        }
        if(pos == -1 && pos2== -1){
            int ans = 1;
            for(int i = 0;i<n;i++){
                if(i&1)(ans*=6);
                else (ans*=20);
            }
            int ans2 = 1;
            for(int i = 0;i<n;i++){
                if(i&1)(ans2*=20);
                else (ans2*=6);
            }
            int res = (ans+ans2);
            cout<<"String #"<<id<<": "<<res<<endl;
        }
        else if((pos!=-1 && pos&1) || pos2%2==0 ){
            int res = 1;
            for(int i= 0;i<n;i++){
                if(s[i]== '?' && i&1)(res*=6); 
                else if(s[i]== '?' && (i%2)==0)(res*=20);
            }
            cout<<"String #"<<id<<": "<<res<<endl;
        }
        else{
            int res = 1;
            for(int i= 0;i<n;i++){
                if(s[i]== '?' && i&1)(res*=20); 
                else if(s[i]== '?' && (i%2)==0)(res*=6);
            }
            cout<<"String #"<<id<<": "<<res<<endl;
        }
        cout<<endl;
        id++;
    }
}   