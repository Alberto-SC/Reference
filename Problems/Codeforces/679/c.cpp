#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    vector<int> str(6);
    for(auto &c:str)cin>>c;
    cin>>n;
    vector<int> notes(n);
    for(auto &c:notes)cin>>c;

    vector<pair<int,int>> all;
    int ans = 1000000007;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<n;j++){
            int x = notes[j]-str[i];
            all.push_back({x,j});
        }
    }
    sort(all.begin(),all.end());
    int l = 0,r  = 0;
    set<int> st;
    // for(auto c:all){cout<<"("<<c.first<<","<<c.second<<") ";}
    // cout<<endl;
    map<int,int> mp;
    while(l<all.size() && r<all.size()){
        st.insert(all[r].second);
        mp[all[r].second]++;
        if(st.size()== n){
            // cout<<l<<" "<<r<<endl;
            while(st.size()== n){
                ans = min(ans,all[r].first-all[l].first);
                mp[all[l].second]--;
                if(mp[all[l].second] == 0)
                    st.erase(all[l].second);
                l++;
            }
            // cout<<l<<" "<<r<<endl;
        }
        r++;
    }
    cout<<ans<<endl;
    return 0;
}

