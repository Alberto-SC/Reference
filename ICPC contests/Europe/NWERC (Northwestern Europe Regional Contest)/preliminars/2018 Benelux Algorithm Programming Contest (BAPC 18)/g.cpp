#include <bits/stdc++.h>
using namespace std;
#define M1 1000000007
#define M2 998244353
#define lli long long
#define ld long double


lli mod_pow(lli a,lli b ,lli m){
    lli x = 1;
    while(b){
        if(b&1)
            (x*=a)%=m
        (a*=a)%=m;
        b>>=1;
    }
    return x;
}

lli modI(lli a, lli m){
    lli m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1){
        lli q=a/m;
        lli t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

void fft(vector<lli> &a,lli n,bool invert,lli m,lli x){
    for(int i = 0;i<n;i++){
        lli y=0;
        for(int j = 0;j<__builtin_ctzlli(n);j++){
            if((1LL<<j)&i){
                y|=(1LL<<(__builtin_ctzlli(n)-j-1));
            }
        }
        if(y>i){
            swap(a[i],a[y]);
        }
    }
    if(invert) x=modI(x,m);
    for(int s = 1;s<__builtin_ctzlli(n)+1,s++){
        lli y=mod_pow(x,(n/(1LL<<s)),m);
        for(int j= 0;j<(n/(1LL<<s));j++){
            lli r=1;
            for(int i = 0;i<(1LL<<(s-1));i++){
                lli u=a[i+j*(1LL<<s)];
                lli v=(r*a[i+j*(1LL<<s)+(1LL<<(s-1))])%m;
                a[i+j*(1LL<<s)]=u+v;
                if(a[i+j*(1LL<<s)]>m) a[i+j*(1LL<<s)]-=m;
                a[i+j*(1LL<<s)+(1LL<<(s-1))]=u-v;
                if(a[i+j*(1LL<<s)+(1LL<<(s-1))]<0) a[i+j*(1LL<<s)+(1LL<<(s-1))]+=m;
                r*=y;
                r%=m;
            }
        }
    }
    if(invert){
        lli invn=modI(n,m);
        for(int i = 0;i<n;i++){ 
            a[i]=(a[i]*invn)%m;
        }
    }
}

void PolyMult(vector<lli>  &a,vector<lli> &b,vector<lli> &v,lli m,lli x){
    lli n=1;
    while(n<((lli)a.size())+((lli)b.size())){ 
        n<<=1;
    }
    vector<lli> fa(a.begin(),a.end());
    fa.resize(n,0);
    vector<lli> fb(b.begin(),b.end());
    fb.resize(n,0);
    lli y=mod_pow(x,(m-1)/n,m);
    fft(fa,n,false,m,y);
    fft(fb,n,false,m,y);
    v.resize(n,0);
    REP(i,0,n){
        v[i]=((fa[i]*fb[i])%m);
    }
    fft(v,n,true,m,y);
    v.resize(((lli)a.size())+((lli)b.size())-1,0LL);
    return;
}

// void PolyInverse(V(lli) &a,V(lli) &v,lli n,lli m,lli x){
//     v.clear();
//     v.PB(modI(a[0],m));
//     while(((lli)v.size())<n){
//         lli tmpsz=(((lli)v.size())<<1);
//         V(lli) tmpa(tmpsz,0LL);
//         REP(i,0,min(((lli)a.size()),tmpsz)){
//             tmpa[i]=a[i];
//         }
//         V(lli) tmppr;
//         PolyMult(tmpa,v,tmppr,m,x);
//         tmppr.resize(tmpsz,0LL);
//         REP(i,0,tmpsz){
//             tmppr[i]=((M2-tmppr[i])%M2);
//         }
//         tmppr[0]=((tmppr[0]+2)%M2);
//         V(lli) tmpv(v.begin(),v.end());
//         PolyMult(tmppr,tmpv,v,m,x);
//         v.resize(tmpsz,0LL);
//     }
//     v.resize(n,0LL);
//     return;
// }

// void PolyDiv(V(lli) &a,V(lli) &b,V(lli) &q,V(lli) &r,lli m,lli x){
//     if(((lli)a.size())<((lli)b.size())){
//         r=a;
//         r.resize(((lli)b.size())-1,0LL);
//         q.clear();
//         q.PB(0LL);
//         return;
//     }
//     V(lli) ra(((lli)a.size())-((lli)b.size())+1,0LL);
//     REP(i,0,((lli)a.size())-((lli)b.size())+1){
//         ra[i]=a[((lli)a.size())-1-i];
//     }
//     V(lli) rb(((lli)b.size()),0LL);
//     REP(i,0,((lli)b.size())){
//         rb[i]=b[((lli)b.size())-1-i];
//     }
//     V(lli) irb;
//     PolyInverse(rb,irb,((lli)a.size())-((lli)b.size())+1,m,x);
//     V(lli) rq;
//     PolyMult(ra,irb,rq,m,x);
//     rq.resize(((lli)a.size())-((lli)b.size())+1,0LL);
//     q.resize(((lli)a.size())-((lli)b.size())+1,0LL);
//     REP(i,0,((lli)rq.size())){
//         q[i]=rq[((lli)rq.size())-1-i];
//     }
//     V(lli) tmppr;
//     PolyMult(b,q,tmppr,m,x);
//     r.resize(((lli)b.size())-1,0LL);
//     REP(i,0,((lli)r.size())){
//         r[i]=((a[i]+M2-tmppr[i])%M2);
//     }
//     return;
// }


 
int main(){__
    int n,m;
    cin>>n;
    string s,t = "";
    cin>>s;
    vector<int> b(3);
    int mn = n+1;
    for(int i = 0;i<n;i++)
        b[s[i]-'A']++;

    string aux = "";    
    for(int i = 0;i<3;i++){
        for(int j = 0;j<b[i];j++){
            aux+=char(i+'A');
        }
    }
    t+=aux;
    t+=aux;
    aux = "";
    for(auto c:{0,2,1}){ 
        for(int j = 0;j<b[c];j++){
            aux+=char(c+'A');
        }
    }
    t+=aux;
    t+=aux;
    m = t.size();
    swap(s,t);
    swap(n,m);
    vector<char> alpha = {'A','B','C'};
    vector<lli> ans((n-m)+1);
    for(char c:alpha){
        vector<lli> X(n), Y(m);
        for(int i = 0; i < n; i++) s[i]== c?X[i] = 1:X[i] = 0;
        for(int i = 0; i < m; i++) t[i]== c?Y[i] = 1:Y[i] = 0;
        reverse(Y.begin(),Y.end());
        vector<lli> x;
        PolyMult(X,Y,x,M1,1);
        // mult<998244353, 3>(X, Y);
        for(int i = 0;i<(n-m)+1;i++)
            ans[i] += x[i+(m-1)];
    }
    // print(ans)
    for(int i = 0;i<ans.size();i++)
        mn = min(m-ans[i],mn);
    cout<<mn<<endl;
    return 0;
}