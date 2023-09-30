#include <bits/stdc++.h>
using namespace std; 
const int block = 316; 
typedef long long int lli;
struct Query {
    int l, r, id;
    bool operator < (const Query other) const {
        return r < other.r;
    }
};
 
int mp[1<<20];
lli total = 0;
int k;
 
void add(int v) {
    total += mp[v^k];
    mp[v]++;
}
 
void rem(int v) {
    mp[v]--;
    total -= mp[v^k];
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int n,m,l,r;
    cin>>n>>m >>k;
    vector<int> a(n);
    for(auto &c:a)cin>>c; 
    vector<int> pref(n+1);
    for(int i=1;i<=n;i++) 
        pref[i]=pref[i-1]^a[i-1];

    vector<vector<Query>> blocks(n/block+2,vector<Query>());
    for (int i = 0; i < m; i++) {
        cin>>l>>r;
        l--; r++;
        blocks[l/block].push_back({l,r,i});
    }
    for (auto &i: blocks) 
        sort(i.begin(), i.end());

 
    vector<lli> ans(m);
    for (int i = 0; i < blocks.size(); i++) {
        int L, R;
        L = R = i * block;
        for (auto &q: blocks[i]) {
            while (R < q.r) {
                add(pref[R]);
                R++;
            }
            while (L < q.l) {
                rem(pref[L]);
                L++;
            }
            while (L > q.l) {
                L--;
                add(pref[L]);
            }
            ans[q.id] = total;
        }
        for (int j = L; j < R; j++) {
            rem(pref[j]);
        }
    }
 
    for (auto c: ans)cout<<c<<endl;
}