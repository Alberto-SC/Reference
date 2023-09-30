#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1000000;
int lp[N+1];
vector<int> primes;
void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}

unordered_map<int,int> factorize(int x){
    unordered_map<int,int> f;
    while(x>1){
        f[lp[x]]++;
        x/=lp[x];
    }
    return f;
}
vector<int> pr[300007];

signed main(){__
    int T = 1,n;
    sieve();
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        unordered_map<int,unordered_set<int>> pos;
        int s,t;
        cin>>s>>t;
        s--,t--;
        for(int i = 0;i<n;i++){
            auto f = factorize(nums[i]);
            for(auto c:f){
                if(i!=s)
                    pos[c.first].insert(i);
                pr[i].push_back(c.first);
            }
        }
        queue<int> q;
        vector<int> dist(n,1e9);
        dist[s] = 0;
        q.push(s);
        vector<int> p(n,-1);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto c:pr[u]){
                pos[c].erase(u);
            }
            for(auto c:pr[u]){
                vector<int> erase;
                for(auto v:pos[c]){
                    if(dist[v]!=1e9){
                        erase.push_back(v);
                        continue;
                    }
                    q.push(v);
                    p[v] = u;
                    dist[v] = dist[u]+1;
                    erase.push_back(v);
                }
                for(auto v:erase){
                    pos[c].erase(v);
                } 
            }
        }
        if(dist[t]==1e9)cout<<-1<<endl;
        else {
            cout<<dist[t]+1<<endl;
            vector<int> ans;
            while(p[t] !=-1){
                ans.push_back(t);
                t = p[t];
            }
            ans.push_back(s);
            reverse(ans.begin(),ans.end());
            for(auto c:ans)cout<<c+1<<" ";
            cout<<endl;
        }

    }
    return 0;
}