#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A)for(auto c:A){print(c);}
#define x first
#define y second
const int maxn = 200007; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    for (++idx; idx <= n; idx += idx & -idx) bit[idx] += delta;
}
bool comp(pair<int,int> a,pair<int,int>b){
    if(a.x == b.x)return a.y<b.y;
    return a.x>b.x;
}
ordered_set s;
int main(){
    int k,pos,m;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<pair<int,int>> copy(n);
    for(int i = 0;i<n;i++)
        copy[i] = {nums[i],i};
    sort(copy.begin(),copy.end(),comp);
    cin>>m;
    vector<pair<pair<int,int>,int>>querys(m);
    // for(auto c:copy)cout<<c.x<<" "<<c.y    <<endl;
    for(int i = 0;i<m;i++){
        cin>>k>>pos;
        querys[i] = {{k,pos},i};
    }
    sort(querys.begin(),querys.end());
    vector<int> ans(m);
    bit.resize(n+7);
    int j = 0;
    n+=7;
    for(int i = 0;i<m;i++){
        while(j<querys[i].x.x)
            s.insert(copy[j++].y);
        
        ans[querys[i].y] = nums[*s.find_by_order(querys[i].x.y-1)];
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;   
}
