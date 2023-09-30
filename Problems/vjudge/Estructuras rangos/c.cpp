#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
bool comp(pair<int,pair<int,int>> A,pair<int,pair<int,int>>B){
    return A.second.second<B.second.second;
}
vector<int> bit;
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
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
}
int main(){
    int m,l,r;
    cin>>n;
    bit.resize(n+7,0);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cin>>m;
    vector<pair<int,pair<int,int>>> querys(m);
    for(int i = 0;i<m;i++){
        cin>>l>>r;
        querys[i] = {i,{l,r}};
    }
    sort(querys.begin(),querys.end(),comp);
    map<int,int> mp;
    int R = 0;
    n++;
    vector<int> ans(m);
    for(int i = 0;i<m;i++){
        while(R<=querys[i].second.second-1){
            int x =nums[R];
            if(mp.find(x) ==mp.end())
                mp[x] = R;
            else 
                add(mp[x],-1),mp[x] = R;
            add(R++,1);
        }
        // print(bit);
        ans[querys[i].first] = sum(querys[i].second.first-1,querys[i].second.second-1);
    }
    for(auto c:ans)cout<<c<<endl;
    cout<<endl;
    return 0;
}