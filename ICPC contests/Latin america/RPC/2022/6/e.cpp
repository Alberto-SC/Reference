#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int inf = 1e18;

signed main(){__
    int t,n,m,q,id,d,c;
    cin>>n>>m;
    vector<pair<int,int>> roads[n];
    vector<int> last(n);
    for(int i = 0;i<m;i++){
        cin>>id>>d>>c;
        id--;
        roads[id].push_back({c,d});
    }
    cin>>q;
    vector<pair<int,int>> cars;
    for(int i = 0;i<q;i++){
        cin>>c;
        cars.push_back({c,i});
    }
    sort(cars.begin(),cars.end());
    set<pair<int,pair<int,int>>> st;
    int res = 0;
    bool flag = true;
    for(int i = 0;i<n-1;i++){
        sort(roads[i].begin(),roads[i].end());
        int mn = inf,idx = -1;
        for(int j = 0;j<roads[i].size();j++){
            if(roads[i][j].second<mn){
                mn = roads[i][j].second;
                idx = j;
            }
        }
        st.insert({roads[i][idx].first,{roads[i][idx].second,i}});
        res+=roads[i][idx].second;
        last[i]= idx+1;
    }
    vector<string> ans(q,"impossible");
    for(int i = 0;i<q;i++){
        c = cars[i].first;
        id = cars[i].second;
        // cout<<"CAR: "<<id<<" "<<c<<endl;
        // cout<<st.begin()->first<<endl;
        vector<int> to_erase;
        while(st.size() && st.begin()->first<c){
            res-=st.begin()->second.first;
            int idx = st.begin()->second.second;
            // cout<<idx<<" "<<res<<endl;
            st.erase(st.begin());
            to_erase.push_back(idx);
        }
        for(auto c:to_erase){
            // cout<<"REPLACE "<<c<<" "<<last[c]<<" "<<roads[c].size()<<endl;
            int mn = 1e9,mnidx = -1;
            for(int j = last[c];j<roads[c].size();j++){
                // cout<<roads[c][j].first<<" "<<roads[c][j].second<<endl;
                if(roads[c][j].second<mn){
                    mn = roads[c][j].second;
                    mnidx = j;
                }
            }
            for(int j = last[c];j<roads[c].size();j++){
                if(roads[c][j].second==mn){
                    last[c] = j+1;
                    break;
                }
            }
            if(mnidx==-1){
                flag = false;
            }
            res+=mn;
            st.insert({roads[c][mnidx].first,{mn,c}});
        }
        if(flag)
            ans[id] = to_string(res);
        else 
            break;
    }
    for(auto c:ans)cout<<c<<endl;

}   