#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
            |   
        bool up = false,lw = false,di = false;
        int inddi,indlw,indup,lwc = 0,upc = 0,dic= 0;
        cin>>s;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')lw = true,indlw = i,lwc++;
            if(s[i]>='A' && s[i]<='Z')up = true,indup = i,upc++;
            if(s[i]>='0' && s[i]<='9')di = true,inddi = i,dic++;
        }
        int how = lw+up+di;
        if(how==3)s = s;
        if(how==1 && lw)s[0] = 'A',s[1] = '1';
        if(how==1 && up)s[0] = 'a',s[1] = '1';
        if(how==1 && di)s[0] = 'A',s[1] = 'a';
        if(how==2){
            if(!lw)upc>1?s[indup] = 'a':s[inddi] = 'a';
            if(!up)lwc>1?s[indlw] = 'A':s[inddi] = 'A';
            if(!di)upc>1?s[indup] = '1':s[indlw] = '1';
        }
        cout<<s<<endl;
    }
    return 0;
}