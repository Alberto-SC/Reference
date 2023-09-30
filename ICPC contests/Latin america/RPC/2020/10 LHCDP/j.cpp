#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
lli DP[61][61][33*33];

lli numS(int n,int bs,int inv){
    if(n == 0 && inv==0)return 1;
    if(n == 0)return 0;
    lli &x = DP[n][bs][inv];
    if(x != -1)return x;
    lli ans = 0;
    ans+=numS(n-1,bs+1,inv);
    ans+=numS(n-1,bs,inv-bs);
    return x = ans;
}
void print(int n,int bs,int inv,lli idx){
    if(n == 0)return ;
    if(n == 0 && inv == 0)return ;
    lli ans = numS(n-1,bs,inv-bs);
    // cout<<ans<<" "<<idx<<endl;   
    if(ans<=idx){
        cout<<"B";
        print(n-1,bs+1,inv,idx-ans);
    }
    else{
        cout<<"A";
        print(n-1,bs,inv-bs,idx);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    memset(DP,-1,sizeof(DP));
    lli m = numS(n,0,k);
    // cout<<m<<endl;  
    if(m&1){
        lli idx = m>>1;
        print(n,0,k,idx);
        cout<<endl;
    }
    else{
        lli idx = (m>>1)-1;
        lli idx2 = m>>1;
        print(n,0,k,idx);
        cout<<endl;
        print(n,0,k,idx2);    
        cout<<endl;
    }
    return 0;
}