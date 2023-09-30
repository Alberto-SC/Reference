#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t,n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    a.resize(2*n);
    vector<pair<int,int>> positions(n);
    for(int i = n;i<2*n;i++)
        a[i] = a[i-n];
    for(int i = 0;i<n;i++)
        positions[b[i]-1] = {i,i+n};
    
    vector<int> ans(2*n);
    vector<int> buck(n);
    for(int i = 0;i<n;i++){
        if(positions[a[i]-1].first<i)ans[i] = positions[a[i]-1].second-i;
        else ans[i] = positions[a[i]-1].first-i;
    }
     for(int i = n;i<2*n;i++){
        if(positions[a[i]-1].second>i)ans[i] = i-positions[a[i]-1].first;
        else ans[i] = i -positions[a[i]-1].second;
    }
    int ans1 = 0,ans2;
    for(int i = 0;i<n;i++){
        buck[ans[i]]++;
        ans1  = max(buck[ans[i]],ans1);
    }
    buck.assign(n,0);
    for(int i = n;i<2*n;i++){
        buck[ans[i]]++;
        ans2  = max(buck[ans[i]],ans2);
    }
    cout<<max(ans1,ans2)<<endl;
    return 0;
}