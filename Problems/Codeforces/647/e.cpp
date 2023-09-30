#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
typedef long long int lli;
const lli mod = 1000000007;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define MOD(n) ( ( ((n) % (mod)) + (mod) ) % (mod))

lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1)x = (x*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return x;
}
lli isp(lli x ,lli diff,lli p){
    if(p == 1)return x;
    lli nd = 1;
    for(lli i = 0;i<diff;i++){
        nd*=p;
        if(nd>maxn)return -1;
    }
    if(x*nd>maxn)return -1;
    return x*nd;

}
vector<int> fr(maxn);
int main(){__
    lli t,n,p,ki;
    cin>>t;
    while(t--){
        cin>>n>>p;
        vector<int> k(n);
        int mx = -1;
        for(int i = 0;i<n;i++){
            cin>>k[i];
            mx = max(k[i],mx);
        }
        for(int i = 0;i<n;i++)fr[k[i]]++;
        sort(k.rbegin(),k.rend());
        k.erase(unique(k.begin(),k.end()),k.end());
        int i = 0;
        lli ans = 0,need = 1;
        while(i<k.size()){
            if(fr[k[i]]%2== 0){i++;continue;}
            bool pos  = false;
            lli last = k[i];
            need = 1;
            for(int j = i+1;j<k.size();j++){
                lli nd = isp(need,last-k[j],p);
                if(nd == -1)break;
                if(nd<= fr[k[j]]){
                    pos = true;
                    fr[k[j]]-=nd;
                    i = j;
                    break;
                }
                else{
                    need = nd-fr[k[j]];
                    last = k[j];
                }
            }   
            if(pos == false){
                ans = mod_pow(p,k[i]);
                for(int j = i+1;j<k.size();j++){
                    ans -= (mod_pow(p,k[j])*fr[k[j]])%mod;
                    if(ans<0)ans+=mod;
                }
                break;
            }

        }
        for(int i = 0;i<k.size();i++)fr[k[i]] = 0;
        cout<<ans<<endl;
    }

    return 0;
}