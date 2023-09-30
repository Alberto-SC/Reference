#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,s,d,i;
    cin>>t;
    while(t--){
        cin>>s>>d;
        bool find = false;
        
        for(i = 0;i<s;i++)
            if(i+(i+d) == s){find = true;break;}
        if(find|| (s== 0&&d == 0)) cout<<i+d<<" "<<i<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}