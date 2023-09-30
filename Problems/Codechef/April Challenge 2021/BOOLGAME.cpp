#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct segments{
    int l,r,c;
};
const int inf = 1e15;
vector<int> transitions(60*60);
vector<int> costs(60*60);
vector<int> DP(60*60,-inf);
vector<int> mask(60*60);
vector<int> maskTimes(60*60);
int sz = 60;
int N,mx = 1e18;
int solve(int idx){
    if(idx >= N){
        mask[idx] = 0;
        return 0;
    }
    int &x = DP[idx];    
    if(x!=-inf)return x;
    int n_take = solve(idx+1);
    int take = solve(transitions[idx])+costs[idx];
    if(n_take>take){   
        maskTimes[idx] = maskTimes[idx+1];
        mask[idx] = mask[idx+1];
        x = n_take;
    }
    else {
        if(take ==n_take)
            maskTimes[idx] = (1<<idx) +maskTimes[idx+1];
        else
            maskTimes[idx] = maskTimes[transitions[idx]];
        mask[idx] = (1<<idx)+mask[transitions[idx]];
        x = take;

    }
    return x;
}

signed main(){
	int t= 1,n,m,k,l,r,c;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        DP.assign(60*60,-inf);
        mask.assign(60*60,0);
        maskTimes.assign(60*60,0);
        vector<int> g(n+1);
        for(int i = 1;i<=n;i++)cin>>g[i];
        vector<segments> sm(m);
        vector<vector<pair<int,int>>> seg(n+1);
        for(int i = 0;i<m;i++){
            cin>>l>>r>>c;
            seg[l].push_back({i,c});
            seg[r].push_back({i,c});
            sm[i] ={l,r,c};
        }
        vector<vector<pair<int,int>>> dp(n+1);
        dp[0].push_back({0,0});
        for(int i = 1;i<=n;i++){
            vector<pair<int,int>> current = dp[i-1];
            int curr = 0,mask = 0;
            map<int,int> open;
            for(int j = i;j>=1;j--){
                curr+=g[j];
                mask^=(1ll<<j);
                for(auto &[idx,x]:seg[j]){
                    if(open.count(idx))
                        curr+=x;
                    else 
                        open[idx]++;
                }
                if(j>1)
                    for(auto &[val,last]:dp[j-2])
                        current.push_back({val+curr,mask^last});
                else
                    current.push_back({curr,mask});
            }

            sort(current.rbegin(),current.rend());
            set<int> used;
            int cont =0;
            for(int j = 0;j<current.size()&& cont<k;j++){
                if(used.count(current[j].second))continue;
                dp[i].push_back(current[j]);
                used.insert(current[j].second);
                cont++;
            }
        }
        for(int i = 0;i<k;i++)
            cout<<dp[n][i].first<<" ";
        cout<<endl;
        // int st1 = 0,id=0;
        // vector<bitset<60>> masks;
        // for(int i = 0;i<n;i++){
        //     st1 += n-i;
        //     int st = st1;
        //     for(int j = i;j<n;j++){
        //         int s =0;
        //         bitset<60> msk;
        //         for(int k = i;k<=j;k++){
        //             s+=g[k];
        //             msk[k] = 1;
        //         }
        //         masks.push_back(msk);
        //         for(int k = 0;k<m;k++){
        //             if(sm[k].l>= i && sm[k].r<=j)s+=sm[k].c;
        //         }
        //         st+=(n-(j+1));
        //         transitions[id]=st;
        //         costs[id] =s;
        //         id++;   
        //     }
        // }
        // vector<pair<int,bitset<sz>>> C;
        // N = (n*(n+1))/2;
        // for(int i = 0;i<N;i++)
        //     C[i] = {costs[i],masks[i]};

        // mn = abs(mn);
        // mx = solve(0);
        // bitset<60> ans = bitset<60>(mask[0]);
        // bitset<60> times = bitset<60>(maskTimes[0]);
    }
    return 0;
}  
