#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int N = 100001;
vector<int> greatestPrime;

typedef vector<int>::iterator it;
void greatestPrimeSieve(int n){
    greatestPrime.resize(n + 1, 1);
    greatestPrime[0] = greatestPrime[1] = 0; 
    for(int i = 2; i <= n; ++i) greatestPrime[i] = i; 
    for(int i = 2; i <= n; i++) 
        if(greatestPrime[i] == i) 
            for(int j = i; j <= n; j += i) 
                greatestPrime[j] = i; 
}

struct wavelet{
    vector<vector<int>> mapLeft,sumLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(mx*2),mx(mx),sumLeft(mx*2){
        build(A.begin(),A.end(),0,mx,1);
    }
    void build(it s,it e,int l,int r,int v){
        if(l== r)return;
        int m = (l+r)>>1;
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        sumLeft[v].reserve(e-s+1);
        sumLeft[v].push_back(0);
        auto f = [m](int x){
            return x<=m;
        };
        for(it iter = s; iter!= e;iter++){
            mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
            sumLeft[v].push_back(sumLeft[v].back() + (*iter<=m)*(*iter));
        }
        it p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }

    int l,r;
    int range(int i ,int j ,int a,int b){
        if( b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx,1);
    }

    int range(int i, int j,int a,int b,int v){
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }
};


signed main(){__
    int q,n,k;
    cin>>q;
    greatestPrimeSieve(N);

    wavelet wt(greatestPrime,1000001);

    while(q--){
        cin>>n>>k;
        cout<<wt.range(0,n,2,k)<<endl;
    }

    return 0;
}
