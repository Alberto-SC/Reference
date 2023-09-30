#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    vector<int> p(k);
    for(auto &c:p)cin>>c;
    vector<pair<int,int>> v(k);
    vector<int> ac(k+1);
    for(int i = 0;i<k;i++)
        v[i] = {p[i],i};
    

    sort(v.begin(),v.end());
    vector<int> ans(k);

    int sum = 0;


    for(int i = 0;i<n;i++){
        sum+=nums[i];
        if(sum>=0){
            sum = 0;
            continue;
        }
        long double x = sum/5.0;
        int y = floor(abs(x));

        int idx = upper_bound(v.begin(),v.end(),make_pair(y,k+1))-v.begin();
        ac[idx]--;
        ac[0]++;
    }

    for(int i = 1;i<k;i++){
        ac[i]+=ac[i-1];
    }
    for(int i = 0;i<k;i++){
        ans[v[i].second] = ac[i];
    }
    for(int i = 0;i<k;i++){
        cout<<ans[i];
        if(i!= k-1)cout<<" ";
    }
    cout<<endl;
    return 0;
}