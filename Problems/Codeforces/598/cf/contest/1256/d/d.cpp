#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1000007;
vector<int> bit(maxn);

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
// ************This only can accept querys in a point*****************
void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s; 
        cin>>s;
        int last = 0;
        vector<int> pos(n);
        iota(pos.begin(),pos.end(),0);
        for(int i = 0;i<n+5;i++)
            bit[i] = 0;
    
        for(int i = 0;i<n;i++)
            range_add(i,i,i);
        for(int i = 0;i<n;i++){
            if(!k)break;
            if(s[i]=='1')continue;
            int d = i-last;
            d = min(d,k);
            k-=d;
            pos[i] = i-d;
            range_add(i-(d+last),i-1,1);
            last++;
        }
        string ans(n,'0');
        for(int i = 0;i<n;i++){
            if(s[i]=='1')
                ans[sum(i)] = '1';
            else 
                ans[pos[i]] = '0';
        }
        cout<<ans<<endl;
    }
    return 0;
}  
