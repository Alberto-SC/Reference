#include <bits/stdc++.h>
using namespace std;
vector<map<int,int> > s;
int last(int a, int w){
    auto it = s[a].lower_bound(w);
    if(it == s[a].begin()) return 1;
    it--;
    return (it->second)+1;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,w;
    cin>>n>>m;
    s.resize(n+1);
    int ans = 0;
    while(m--){
        cin>>a>>b>>w;
        int val = last(a,w);
        int val2 = last(b,w+1);
        // cout<<val<<" "<<val2<<endl;
        if(last(b,w+1)> val)
            continue;
        s[b][w] = max(s[b][w],val);
        auto it = s[b].upper_bound(w);
        // cout<<it->first<<" "<<it->second<<endl;
        while(!(it==s[b].end() || it->second > val)){
            // cout<<"HELLO"<<endl;
            it = s[b].erase(it);
        }
        ans = max(ans,val);
    }
    cout<<ans<<endl;
    return 0;
}
