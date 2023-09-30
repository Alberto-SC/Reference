#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
map<int,int> fact;
int c;

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}

bool isSquare(int x){
    c = 1;
    fact.clear();
    while(x%2==0){
        fact[2]++;
        x/=2;
    }
    for(int i = 3;i*i<=x;i+=2){
        while(x%i==0){
            fact[i]++;
            x/=i;
        }
    }
    if(x>1)
        fact[x]++;

    for(auto &d:fact){
        if(d.second&1)return false;
        d.second/=2;
        c*=bin_pow(d.first,d.second);
    }
    return true;
}

signed main(){__
    int t,n;
    cin>>t;
    vector<int> ans(3001,-1);
    for(int i = 1;i<=1000;i++){
        for(int j = i+1;j<1500;j++){
            int x = (i*i)+(j*j);
            if(isSquare(x)){
                if(c+i+j<=3000 && i<j && j<c){
                    ans[c+i+j] = max(ans[c+i+j],c*i*j);
                }
            }
        }
    }
    while(t--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
