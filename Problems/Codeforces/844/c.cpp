#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        map<char,int> mp;
        vector<int> divs;
        for(int i = 1;i*i<=n;i++){
            if(n%i ==0){
                divs.push_back(i);
                if(n/i !=i)divs.push_back(n/i);
            }
        }


        for(auto c:s){
            mp[c]++;
        }
        int ans = 1e9;
        string sans = "";
        vector<int> pos[26];
        for(int i =0 ;i<n;i++){
            pos[s[i]-'a'].push_back(i);
        }
        vector<int> unused;
        for(int i = 0;i<26;i++){
            if(mp.count(i)==0)unused.push_back(i);
        }


        for(auto d:divs){
            vector<pair<int,char>> l;
            vector<pair<int,char>> r;
            int need = n/d;
            int res = 0;
            if(d >26)break;
            int cont = d;
            string sres = s;
            int idx = 0;
            vector<int> idxs(26,0);
            for(auto c:mp){
                if(c.second> need){
                    res+=c.second-need;
                    for(int k = (c.second-need)/need;k++){
                        for(int z = 0;z<need;z++){
                            sres[idxs[c.first]] = char(unused[idx]+'a');
                            idxs[c.first]++;
                        }
                        idx++;
                    }
                    if(c.second&need)
                        r.push_back(c.second%need);

                }
                else if(c.second< need){
                    l.push_back(c.second);
                }
            }
            sort(l.begin(),l.end());
            int idxr = 0;
       
            
            while (idxr<r.size()){
                int mn = min(need-l.back(),r[idxr]);
                r[idxr]-=mn;
                l.back()+=mn;
                if(l.back()==need)l.pop_back();
                if(r[idxr]==0)idxr++;
                break;
            }
            
            int s = accumulate(l.begin(),l.end(),0);
            int x = s/need;

            for(int i = 0;i<l.size()-x;i++){
                res+=l[i];
            }

            ans = min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}