#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli countbits(lli A,lli B){
    lli count = 0;   
    // if(A==1)return 0;
    for (int i = 0; i < 63; i++) { 
        if (((A >> i) & 1) != ((B >> i) & 1)) { 
            count++; 
        } 
    } 
    return count;
}

bool is_pow(lli x){
    lli r = 1;
    while(r<x){
        r<<=1;
    }
    if(r ==x)return true;
    return false;
}

vector<lli> ac(63);
lli solve(lli x){
    lli ans = 0;
    for(int i = 0;i<63;i++)
        if((x>>i)&1)ans+= ac[i];
    return ans;
}


int main(){__
    lli t,n,m;
    cin>>t;
    ac[0] = 1;
    for(int i = 1;i<63;i++){
        ac[i] = (2ll<<i)-1;
    }
    while(t--){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}