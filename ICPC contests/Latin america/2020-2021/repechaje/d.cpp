#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 10000007;
vector<int> primes;
vector<int> lp(M+1);

void criba(){
    for(int i = 2;i<M;i++){
        if(!lp[i]){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]*i<=M && primes[j]<= lp[i];j++)
            lp[primes[j]*i] = primes[j];
    }
}

signed main(){__
    int T = 1,n,k;
    criba();
    cin>>T;
    while(T--){
        cin>>k;
        k+=2;
        vector<int> ans;
        for(int i = 1;i*i<=k;i++){
            if(k%i ==0){
                if(lp[i]==i && i!=2){
                    ans.push_back(i);
                }
                if((k/i)!=i){
                    if(lp[k/i]==k/i && (k/i)!=2){
                        ans.push_back(k/i);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0)cout<<-1;
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}