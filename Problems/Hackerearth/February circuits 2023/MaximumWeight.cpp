#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> w(n);
    for(auto &c:w)cin>>c;
    vector<int> edges(m);
    map<pair<int,int>,int> mp;
    int key = 0;


    vector<int> graph[n];
    
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(u>v)swap(u,v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        
        if(!mp.count({u,v}))mp[{u,v}] = key++;
        edges[mp[{u,v}]]+=2;
    }

    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        v.push_back({w[i],i});
    }
    sort(v.rbegin(),v.rend());

    int count = n,sum = accumulate(w.begin(),w.end(),0ll);
    set<int> ans;
    for(int i = 0;i<n;i++)ans.insert(i);
        
    vector<int> suf(n);
    multiset<int> Mx[m];

    vector<int> used(n);
    for(int i = 0;i<n;i++){
        bool flag = true;
        int u = v[i].second;
        for(auto v:graph[u]){
            int a = u,b = v;
            if(a>b)swap(a,b);
            
            int id = mp[{a,b}];
            edges[id]--;
            if(edges[id]<=0)flag = false;
        }

        if(flag){
            ans.erase(v[i].second);
            count--;
            sum-=v[i].first;
            suf[i] = v[i].first;
            for(auto V:graph[u]){
                int a = u,b = V;
                if(a>b)swap(a,b);
                int id = mp[{a,b}];
                Mx[id].insert(i);
            }
            continue;
        }
        used[i] = true;
        for(auto v:graph[u]){
            int a = u,b = v;
            if(a>b)swap(a,b);
            
            int id = mp[{a,b}];
            edges[id]++;
        }
    }

    for(int i = 0;i<n;i++){
        if(!used[i])continue;

        set<int> add;
        int u = v[i].second;
        int ac = 0;
        bool flag = true;
        vector<pair<int,int>> to_erase;
        for(auto V:graph[u]){
            int a = u,b = V;
            if(a>b)swap(a,b);
            int id = mp[{a,b}];
            
            if(edges[id]>1)continue;

            if(Mx[id].size()==0){
                flag = false;
                break;
            }
            int mx = *Mx[id].rbegin();
            if(!add.count(mx) && !used[mx]){
                add.insert(mx);
                ac+= v[mx].first;
                to_erase.push_back({mx,id});
            }
        }

        if(!flag)continue;

        if(ac>v[i].first)continue;
        int currentAns = count*sum;
        int nwAns = ((count-1)+add.size())*(sum-(v[i].first-ac));
        if(nwAns>currentAns)continue;
        break; 
        used[i] = false;
        count = (count-1)+add.size();
        sum-=v[i].first-ac;
       
        /* for(auto V:graph[u]){ */
        /*     int a = u,b = V; */
        /*     if(a>b)swap(a,b); */
        /*     int id = mp[{a,b}]; */
        /*     if(edges[id]>1) */
        /*         edges[id]--; */
        /* } */
        /**/
        ans.erase(v[i].second);
        for(auto c:to_erase){
            ans.insert(c.first);
            Mx[c.second].erase(Mx[c.second].find(c.first));
            used[c.first] = true;
        }
        break;

   
    }
    
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c+1<<" ";
    cout<<endl;
    return 0;
}
