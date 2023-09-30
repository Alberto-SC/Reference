#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int mod_pow(int a,int b,int mod){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int a,b,c;
    cin>>a>>b>>c;
    if(a%10 ==1 ||a%10 ==5 || a%10 == 6 ||a%10 ==0){
        cout<<a%10<<endl;
    }
    if(a%10 ==2 || a%10 ==3 || a%10 ==7 ||a%10 ==8){
        cout<<mod_pow(a,mod_pow(b,c,4)==0?4:mod_pow(b,c,4),10)<<endl;
    }
    if(a%10 == 4|| a%10 ==9){
        int x = mod_pow(b,c,2);
        if(x==1)cout<<a%10<<endl;
        else if(a%10 ==4)cout<<6<<endl;
        else if(a%10 ==9)cout<<1<<endl;
    }
    return 0;
}  
