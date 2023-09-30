#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        string sl,sr;
        cin>>sl>>sr;
        map<char,vector<int>> l;
        map<char,vector<int>> r;
        for(int i = 0;i<n;i++){
            l[sl[i]].push_back(i+1);
            r[sr[i]].push_back(i+1);
        }
        int ans = 0;
        vector<pair<int,int>> res;
        vector<bool> usedl(n);
        vector<bool> usedr(n);
        for(auto c:l){
            if(c.first=='?')continue;
            if(r.count(c.first)){
                for(int i = 0;i<min(c.second.size(),r[c.first].size());i++){
                    ans++;
                    res.push_back({c.second[i],r[c.first][i]});
                    usedl[c.second[i]-1] = true;
                    usedr[r[c.first][i]-1]  = true;
                }
            }
        }
        int idl = 0;
        for(auto c:l['?']){
            while(idl<n && (usedr[idl]||sr[idl]=='?')){
                idl++;
            }
            if(idl==n)break;
            ans++;
            res.push_back({c,idl+1});
            usedl[c-1] = true;
            usedr[idl] = true;
        }
        idl = 0;
        for(auto c:r['?']){
            while(idl<n && (usedl[idl]||sl[idl]=='?')){
                idl++;
            }
            if(idl==n)break;
            ans++;
            res.push_back({idl+1,c});
            usedr[c-1] = true;
            usedl[idl] = true;
        }
        vector<int> lastl,lastr;
        for(int i= 0;i<n;i++){
            if(sl[i]== '?' && !usedl[i])lastl.push_back(i+1);
            if(sr[i]== '?' && !usedr[i])lastr.push_back(i+1);
        }
        for(int i = 0;i<min(lastl.size(),lastr.size());i++){
            ans++;
            res.push_back({lastl[i],lastr[i]});
        }
        cout<<ans<<endl;
        for(auto c:res)cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}  
