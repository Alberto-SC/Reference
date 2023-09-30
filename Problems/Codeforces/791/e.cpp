#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
const int N = 17;
int F[1<<N][N];

signed main(){__
    int T = 1,n,q;
    cin>>n;
    string s;
    cin>>s;
    vector<string> _all;
    int total = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='?')total++;
    }
    for(int i = 0;i<n;i++){
        string x = "";
        for(int j = i;j<n;j++){
            x+=s[j];
            _all.push_back(x);
        }
    }

    memset(F,0,sizeof(F));

    for(auto c:_all){
        int M = c.size();
        int mask = 0,cont = 0,qm = 0;
        bool flag = true;
        for(int i = 0;i<M/2;i++){
            if(c[i]=='?' && c[(M-1)-i]!='?'){
                mask|=1<<(c[(M-1)-i]-'a');
            }
            else if(c[i]!='?' && c[(M-1)-i]=='?'){
                mask|=1<<(c[i]-'a');
            }
            else if(c[i]=='?' && c[(M-1)-i]=='?'){
                cont++;
            }
            else if(c[i]!=c[(M-1)-i]){
                flag = false;
            }
        }
        if(M&1){
            if(c[M/2]=='?'){
                cont++;
            }
        }
        for(int i =0 ;i<M;i++){
            if(c[i]=='?')qm++;
        }
        if(!flag)continue;
        for(int i = 1;i<=N;i++){

            F[mask][i-1]+= mod_pow(i,cont+(total-qm));
        }

    }

    for(int k = 0;k<N;k++){
        for(int i = 0;i<N;i++){
            for(int mask = 0;mask<(1<<N);mask++){
                if(mask & (1<<i))
                    (F[mask][k] += F[mask ^(1<<i)][k])%=mod;
            }
        }
    }

    cin>>q;
    while(q--){
        cin>>s;
        int mask = 0;
        for(int i = 0;i<s.size();i++){
            mask|=1<<(s[i]-'a');
        }
        int k = __builtin_popcount(mask);
        cout<<F[mask][k-1]<<endl;
    }

    return 0;
}