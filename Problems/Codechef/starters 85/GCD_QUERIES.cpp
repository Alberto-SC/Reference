#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1000007;

map<int,vector<pair<int,int>>> mul;

vector<int> P[maxn];
const int N = 1000007;
int lp[N+1];
vector<int> primes;
void criba(){
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

signed main(){__
    int T = 1,n,q;
    cin>>T;
    criba();
    for(int i =2 ;i<maxn;i++){
        int x = i;
        while(x>1){
            int p = lp[x];
            P[i].push_back(p);
            while(x%p==0)x/=p;
        }
    }

    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cin>>q;

        vector<int> used(n);
        set<pair<int,int>> st;
        vector<pair<int,int>> v(n);

        for(int i = 0;i<n;i++){
            v[i] = {nums[i],i};
        }
        sort(v.rbegin(),v.rend());

        for(int i = 0;i<n;i++){
            st.insert(v[i]);
            for(auto c:P[v[i].first]){
                mul[c].push_back(v[i]);
            }

        }
        while(q--){
            int x;
            cin>>x;
            int ans = 1e9;
            int idx = -1;
            int d = -1;
            for(auto p:P[x]){
                while(mul[p].size() && used[mul[p].back().second]){
                    mul[p].pop_back();
                }
                if(mul[p].size() && mul[p].back().first<ans){
                    ans = mul[p].back().first;
                    idx = mul[p].back().second;
                    d = p;
                }
            }

            if(idx ==-1){
                auto mn = *st.begin();
                cout<<mn.first<<" ";
                used[mn.second] = true;
                st.erase(mn);
            }
            else{
                cout<<ans<<" ";
                used[idx] = true;
                st.erase({ans,idx});
                mul[d].pop_back();
            }
        }

        mul.clear();

        cout<<endl;
    }
    return 0;
}