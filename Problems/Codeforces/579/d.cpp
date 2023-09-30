#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    string s,t;
    cin>>s>>t;
    n = s.size(),m = t.size();
    vector<pair<int,int>> pref(n);
    vector<pair<int,int>> suf(n);
    int id = 0;
    vector<int> L(m+1,-1);
    vector<int> R(m+1,m);

    for(int i = 0;i<n;i++){
        if(id<m && s[i]==t[id] ){
            pref[i] = {++id,i};
            L[id] = i;
        }
        else{
            if(i)
                pref[i] = pref[i-1];
            else pref[i] = {0,-1};
        } 
            
    }
    id = m-1;
    int sz = 0;
    for(int i = n-1;i>=0;i--){
        if(id>=0 && s[i]== t[id] ){
            suf[i] = {++sz,i};
            R[sz] = i;
            id--;
        }
        else {
            if(i!=n-1)
                suf[i] =suf[i+1];
            else 
                suf[i] = {0,n};
        }
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        int l = pref[i].first;
        int ll = pref[i].second;
        ll++;
        int need = m-l;
        int lr = R[need];
        lr--;
        if(ll<=lr){
            ans = max(ans,(lr-ll)+1);
        }
    }
    for(int i = n-1;i>=0;i--){
        int l = suf[i].first;
        int lr = suf[i].second;
        lr--;
        int need = m-l;
        int ll = L[need];
        ll++;
        if(ll<=lr){
            ans = max(ans,(lr-ll)+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}