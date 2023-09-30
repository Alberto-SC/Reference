#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int n;
vector<int> bit;

int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx <= n; idx += idx & -idx) bit[idx] += delta;
}

void print(){
    for(int i = 0;i<n;i++)
        cout<<sum(i,i)<<" ";
    cout<<endl;
}

signed main(){__
	int t= 1,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bit.resize(n+1,0);
        map<int,int> pos;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int inv = 0;
        for(int i = 0;i<n;i++)
            pos[nums[i]-1] = i;
        
        for(int i = 0;i<n;i++){
            inv+=sum(pos[i],n-1);
            add(pos[i],1);
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            cout<<inv<<" ";
            if(inv<=m)
                ans.push_back(i);
            inv-=pos[i];
            inv+=(n-pos[i])-1;
        }
        cout<<endl;
        cout<<ans.size()<<" ";
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
