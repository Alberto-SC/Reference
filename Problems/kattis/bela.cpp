#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    char s;
    cin>>n>>s;
    string h;
    for(int i = 0;i<4*n;i++){
        cin>>h;
        if(h[0] == 'A')ans+=11;
        else if(h[0] == 'K')ans+=4;
        else if(h[0] == 'Q')ans+=3;
        else if(h[0] == 'J')h[1]==s?ans+=20: ans+=2;
        else if(h[0] == 'T')ans+=10;
        else if(h[0] == '9')h[1]==s?ans+=14: ans+=0;
    }
    cout<<ans<<endl;
    return 0;
}