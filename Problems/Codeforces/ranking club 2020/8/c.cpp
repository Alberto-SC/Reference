#pragma GCC optimize ("O3")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> pre;
cc_hash_table<int, int> pre;
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli maxn = 20000000000;
const int N =10000000;
int lp[N+1];

int spf[N]; 

void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<N; i++) 
        spf[i] = i; 
    for (int i=4; i<N; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<N; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<N; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int mobiusF(int x){ 
    vector<int> ret; 
    while (x != 1){ 
        if(ret.size() && spf[x]== ret.back())return 0;
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret.size()%2 == 0?1:-1; 
} 
int n = pow(maxn, (double)2/3);
vector<int> mobius(n);

lli countSquares(lli x){  
    lli ans = 0;
    for(lli i = 1;i<=sqrt(x);i++){
        ans+= mobius[i]*(x/(i*i));
    }
    return ans;
} 
// unordered_map<lli,lli> pre;
// vector<lli>  pre(1000000,-1);
// template <int I, int Z> 
lli Mertens(lli x){
    if(pre.find(x)!= pre.end())return pre[x];
    lli n = x/(lli)sqrt(x);
    lli sum = 0;
    for(lli i =2;i<=n;i++){
        sum +=Mertens(x/i);
    }
    lli sum2 = 0;
    for(lli i= 1;i<=(lli)sqrt(x)-1;i++){
        lli z = x/i;
        z -= x/(i+1);
        sum += z*pre[i];
    }
    pre[x] = 1-sum-sum2;
    return 1-sum-sum2;
}

int main(){
    lli k;
    cin>>k;
    int i;
    sieve();
    pre[1] = 1;
    for(int i = 1;i<n;i++){
        // cout<<i<<endl;
        mobius[i] = mobiusF(i);
    }
    for(int i= 2;i<n;i++){
        pre[i] = pre[i-1]+mobius[i];
    }
    lli l = 1; 
    lli r = maxn;
    while (l < r) { 
        lli mid = l + (r - l)/2;
        lli sq = countSquares(mid);
        lli si = Mertens(mid);
        pre[mid] = si;
        // cout<<mid<<" "<<sq<<" "<<si<<endl;
        lli c = ((sq+si)/2)-1;
        if (c < k) 
            l = mid+1; 
        else
            r = mid; 
    } 
    cout<<l<<endl;
    return 0;
}
