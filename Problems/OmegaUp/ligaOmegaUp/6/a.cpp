#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    set<int> s;
    vector<pair<int,int>> p(n);
    for(int i = 0;i<n;i++){
        p[i] = {nums[i],i+1};
        s.insert(i+1);
    }
    sort(p.begin(),p.end());
    vector<int> ans(n+1);
    for(int i = 0;i<n-1;i++){
        auto it1 = lower_bound(s.begin(),s.end(),p[i].y);
        it1++;
        int ind = *it1;
        if(ind<=p[i].y)ind = n+1;
        ans[p[i].y] = 1;
        ans[p[i].y] += ind-(p[i].y+1);
        int ind1;
        if(p[i].y ==1)continue;
        auto it = lower_bound(s.begin(),s.end(),p[i].y);
        it--;
        ind1 = *it;
        // cout<<ind<<" "<<ind1<<endl;
        ans[p[i].y] += p[i].y-(ind1+1);
        s.erase(p[i].y);
    }
    ans[p[n-1].y] = n;
    for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}