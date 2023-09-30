#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN = 400007;
const int mod = 1000000007;
vector<lli> stP(4*MAXN,1);
vector<lli> lazyP(4*MAXN,1);
vector<lli> stO(4*MAXN,0);
vector<lli> lazyO(4*MAXN,0);
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137
,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293}; // (size = 62)

int mod_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 0) {a = (1LL * a * a) % mod; b /= 2;}
        else {res = (1LL * res * a) % mod; b -= 1;}
    }
    return res;
}
void propagate_product(int v ,int SL, int SR){
    if(lazyP[v] == 1)return ;
    stP[v] =(1ll* stP[v]* mod_pow(lazyP[v],(SR-SL+1)))%mod;
    if(SL!=SR){
        lazyP[v*2] =(1ll*lazyP[v*2]*lazyP[v])%mod;
        lazyP[v*2+1] =(1ll*lazyP[v*2+1]*lazyP[v])%mod;
    }
    lazyP[v] = 1;
}
void Update_product(int v, int SL, int SR, int L, int R, int mult){ 
    propagate_product(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return;
    if(L<=SL && SR<=R){
        lazyP[v] =(1ll * lazyP[v]*mult)%mod;
        propagate_product(v,SL,SR);
        return;
    }
    int SM = (SL+SR)/2;
    Update_product(v*2,SL,SM,L,R,mult);
    Update_product(v*2+1,SM+1,SR,L,R,mult);
    stP[v] = (1ll*stP[v*2]*stP[v*2+1])%mod;
}

lli query_product(int v,int SL,int SR,int L,int R){
    propagate_product(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return 1;
    if(L<=SL && SR<=R)return stP[v];
    int SM = (SL+SR)/2;
    lli p1 = query_product(v*2,SL,SM,L,R);
    lli p2 = query_product(v*2+1,SM+1,SR,L,R);
    return (p1*p2)%mod;
}

void propagate_OR(int v ,int SL, int SR){
    if(lazyO[v] == 0)return ;
    stO[v] |= lazyO[v];
    if(SL!=SR){
        lazyO[v*2] |= lazyO[v];
        lazyO[v*2+1] |= lazyO[v];
    }
    lazyO[v] = 0;
}
void Update_OR(int v, int SL, int SR, int L, int R, lli val){
    propagate_OR(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return;
    if(L<=SL && SR<=R){
        lazyO[v] |=val;
        propagate_OR(v,SL,SR);
        return;
    }
    int SM = (SL+SR)/2;
    Update_OR(v*2,SL,SM,L,R,val);
    Update_OR(v*2+1,SM+1,SR,L,R,val);
    stO[v] = stO[v*2]|stO[v*2+1];
}

lli query_OR(int v,int SL,int SR,int L,int R){
    propagate_OR(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return 0;
    if(L<=SL && SR<=R)return stO[v];
    int SM =(SL+SR)/2;
    lli O1 = query_OR(v*2,SL,SM,L,R);
    lli O2 = query_OR(v*2+1,SM+1,SR,L,R);
    return (O1|O2);
}
vector<lli> mask(301,0);
void PreprocessMask() {
	for (int z=1; z<=300; z++) {
		for (int i=0; i<62; i++) {
			if (z % prime[i] != 0) continue;
			    mask[z] |= (1LL << i);
		}
	}
}
int main(){
    int n,q,m,l,r;
    string s;
    cin>>n>>q;
    vector<lli> invPrimes(62);
    for (int i=0; i<62; i++) invPrimes[i] = mod_pow(prime[i], mod-2);
    PreprocessMask();
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        Update_product(1,0,n-1,i,i,nums[i]);
        Update_OR(1,0,n-1,i,i,mask[nums[i]]);
    }
    for(int i = 0;i<q;i++){
        cin>>s>>l>>r;
        if(s == "MULTIPLY"){
            cin>>m;
            Update_product(1,0,n-1,--l,--r,m);
            Update_OR(1,0,n-1,l,r,mask[m]);
        }
        else{
            long long res = query_product(1,0,n-1,--l,--r);
            long long mask = query_OR(1,0,n-1,l,r);
            for(int i = 0;i<62;i++){
                if((mask & (1ll<<i)) == 0)continue;
                else 
                res = (1ll *res*(prime[i]-1))%mod;
                res = (1ll * res * invPrimes[i])%mod;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}