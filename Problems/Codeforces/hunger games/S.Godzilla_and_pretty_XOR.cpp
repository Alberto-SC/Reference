#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}

struct basisxor{
    int base[32];
    int sz = 0;
    basisxor(){
        for(int i = 0;i<32;i++)
            base[i] =0;
    }
    void add(int x){
        while(x != 0 && base[31-__builtin_clz(x)]!= 0){
            x^= base[31-__builtin_clz(x)];
        }
        if(!x)return;
        base[31-__builtin_clz(x)] = x;
        sz++;
    }

    int kth(int k){
        int total = bin_pow(2,sz);
        int val = 0;
        for(int i = 31;i>=0;i--){
            if(base[i] == 0)continue;
            if(k<total/2){
                if((val>>i)&1)
                    val^=base[i];
            }
            else{
                if(!((val>>i)&1))
                    val^=base[i];
                k-=total/2;
            }
            total>>=1;
        }
        return val;
    }
};

int main(){__
    int n,x,k,t;
    cin>>n;
    basisxor bs;
    for(int i = 0;i<n;i++){
        cin>>t;
        if(t == 1){
            cin>>x;
            bs.add(x);
        }else{
            cin>>k;
            k--;
            cout<<bs.kth(k)<<endl;
        }
    }
    return 0;
}