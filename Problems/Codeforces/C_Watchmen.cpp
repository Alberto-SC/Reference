#include <bits/stdc++.h>
using namespace std;
#define all(A)A.begin(),A.end()
int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> pairs(n);
    vector<int> xs(n);
    vector<int> ys(n);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        pairs[i] = {x,y};
        xs[i] = x;
        ys[i] = y;
    }
    int ans = 0;
    map<pair<int,int>,int>m;
    for(int i = 0;i<n;i++){
        if(m.find(pairs[i]) == m.end())m[pairs[i]] = 0;
        else m[pairs[i]]++;
    }
    for(auto c:m)if(c.second>0)ans+=(c.second*(c.second+1))/2;

    sort(all(xs));
    sort(all(ys));
    int ans2 = 0,search,index;
    for(auto c:m){
        // cout<<"Pair  "<<c.first.first<<" "<<c.first.second<<" "<<c.second<<endl;
        search = upper_bound(all(xs),c.first.first)-xs.begin();
        index = lower_bound(all(xs),c.first.first)-xs.begin();
        ans2+=(search-index)-1;
        if(c.second>0)ans2+=((search-index)-1)*(c.second+1);
        // cout<<index<<"  "<<search<<endl;
        search = upper_bound(all(ys),c.first.second)-ys.begin();
        index = lower_bound(all(ys),c.first.second)-ys.begin();
        ans2+=(search-index)-1;
        if(c.second>0)ans2+=((search-index)-1)*(c.second+1);
        // cout<<index<<"  "<<search<<endl;

    }
    cout<<(ans2/2)-ans<<endl;
    return 0;
}