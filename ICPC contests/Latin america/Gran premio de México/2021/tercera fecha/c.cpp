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

signed main(){
	int t= 1,n,L,mod;
    while(t--){
        cin>>B>>L;
        mod = B+1;
        vector<int> N(L);
        for(auto &c:N)cin>>c;
        int residuo = modulo(N);
        if(residuo==0)return cout<<0<<" "<<0<<endl,0;
        pair<int,int> ans = {-1,-1};
        int cont = 0;
        int res2 = (B+1)-residuo;
        for(int i = L-1;i>=0;i--){
            if(cont&1 && N[i]>=res2){
                ans = {i+1,N[i]-res2};
            }
            else if(cont%2==0 && N[i]>=residuo){
                ans = {i+1,N[i]-residuo};
            } 
            cont++;
        }
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}  
