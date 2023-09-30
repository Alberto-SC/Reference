#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> bit(maxn);

int n;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += delta;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int Dsum(int x){
    int s = 0;
    while(x){
        s+=(x%10);
        x/=10;
    }
    return s;
}

signed main(){__
    int T,l,r,x,q,t;
    cin>>T;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        vector<int> f[n];
     
        for(auto &c:nums)cin>>c;

        for(int i= 0;i<n;i++){
            int last = 1e9;
            int  x= nums[i];
            f[i].push_back(x);
            while(1){
                int s = Dsum(x);
                if(s == last){
                    break;
                }
                else f[i].push_back(s);
                last = s;
                x = s;
            }
        }
        vector<pair<int,int>> er;
        while(q--){
            cin>>t;
            if(t == 1){
                cin>>l>>r;
                l--,r--;
                er.push_back({l,r});
                range_add(l,r,1);
            }
            else{
                cin>>x;
                x--;
                int s = sum(x);
                if(s >= f[x].size())
                    cout<<f[x].back()<<endl;
                else cout<<f[x][s]<<endl;
            }
        }
        for(auto p:er){
            range_add(p.first,p.second,-1);
        }    
    }
    return 0;
}