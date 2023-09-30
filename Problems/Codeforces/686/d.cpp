#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<lli,lli> fact;

lli bin_pow(lli a,lli b){
    lli x= 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
void factorize(lli n){
    while(n%2==0){
        n/=2;
        fact[2]++;
    }
    for(lli i =3;i*i<=n;i+=2){
        while(n%i == 0){
            n/=i;
            fact[i]++;
        }
    }
    if(n>1)
        fact[n]++;
}

int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        fact.clear();
        factorize(n);
        lli y = 1;
        int cont =0;
        vector<lli> ans;
        if(fact.size()==1){
            for(auto c:fact){
                cout<<c.second<<endl;
                for(int i = 0;i<c.second;i++)
                    cout<<c.first<<" ";
            }
            cout<<endl;
            continue;
        }
        lli mxp = 0,mxn = 0;
        for(auto c:fact){
            if(c.second>mxp){
                mxp = c.second;
                mxn = c.first;
            }
        }
        for(int i = 0;i<mxp-1;i++)
            ans.push_back(mxn);
        y = mxn;
        for(auto c:fact){
            if(c.first!=mxn)
                y*=bin_pow(c.first,c.second); 
        }
        ans.push_back(y);
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

