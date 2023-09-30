#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int B;


int modulo(vector<int> &v){
    int x = 1;
    int aux =B;
    int ans = 0;
    int mod = B+1;
    for(int i = v.size()-1;i>=0;i--){
        ans+= v[i]*x;
        ans%=mod;
        (x*=aux)%=mod;
    }
    return ans;
}

signed main(){__
	int t= 1,n,L;
    while(t--){
        cin>>B>>L;
        vector<int> N(L);
        for(auto &c:N)cin>>c;
        int residuo = modulo(N);
        if(residuo==0)return cout<<0<<" "<<0<<endl,0;
        cout<<residuo<<endl;
        pair<int,int> ans = {-1,-1};
        for(int i = L-1;i>=0;i--){
            int aux = N[i];
            for(int j = aux;j>=0;j--){
                N[i] = j;
                if(modulo(N)==0)ans = {i+1,j};
            }
            N[i] = aux;
        }
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}  


5664796
5656008
5664120