#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

const int maxn = 100007;
vector<int> bit(maxn);

void add(int idx,int v){
    for(++idx;idx<maxn;idx+=idx&-idx){
        (bit[idx]+=v)%=mod;
        if(bit[idx]<0)bit[idx]+=mod;
    }
}

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx){
        (res+=bit[idx])%=mod;
        if(res<0)res+=mod;
    }
    return res;
}

int sum(int l,int r){
    int ans = sum(r)-sum(l-1);
    if(ans<0)ans+=mod;
    return ans;
}

signed main(){__
    int T = 1,n,q,l,r;
    cin>>n>>q;
    string s;
    cin>>s;
    int p = n-1;
    for(int i = 0;i<n;i++){
        if(s[i]=='1'){
            add(i,mod_pow(2,p-i));
        }
    }

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            cin>>l;
            l--;
            if(s[l]=='1'){
                add(l,-mod_pow(2,p-l));
                s[l] = '0';
            }
            else{
                add(l,mod_pow(2,p-l));
                s[l] = '1';
            }
        }
        else{
            cin>>l>>r;
            int L =n-r; 
            l--,r--;
            int x = sum(l,n-1);
            if(L ==0){
                cout<<x<<endl;
                continue;
            }
            int y = sum(r+1,n-1);
            x-=y;
            if(x<0)x+=mod;
            int inv = mod_pow(2,L*(mod-2));
            x*=inv;
            x%=mod;
            cout<<x<<endl;
        }
    }
    return 0;
}