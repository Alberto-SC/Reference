#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<char,int>> S(n);
        vector<bool> par(n,false);
        for(int i = 0;i<n;i++)
            cin>>S[i].second;
        for(int i = 0;i<n;i++)
            cin>>S[i].first;
        sort(S.begin(),S.end());
        int contF = 0;
        for(int i = 0;i<n;i++){
            if(S[i].first == 'M')break;
            contF++;
        }    
        int ans = 0;
        for(int i = 0;i<contF;i++){
            for(int j = contF;j<n;j++){
                if(__gcd(S[i].second,S[j].second)>1 && !par[i] && !par[j]){
                    ans++;
                    par[i] = par[j] = true;
                }
            }
        }
        for(int i = 0; i<n;i++)
            if(!par[i])ans++;
        cout<<ans<<endl;
    }
    return 0;
}