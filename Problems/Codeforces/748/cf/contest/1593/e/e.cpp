#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 400007;
vector<int> degree(maxn);
set<int> graph[maxn];
signed main(){
	int t= 1,n,k,u,v;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n;i++)
            graph[i].clear(),degree[i] = 0;
        
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
            graph[v].insert(u);
            degree[u]++;
            degree[v]++;
        }
        set<pair<int,int>> st;
        for(int i = 0;i<n;i++){
            st.insert({degree[i],i});
        } 
        while(k-- && st.size()){
            set<int> to_erase;
            while(st.size()){
                auto x = st.begin();
                if(x->first>1)break;
                to_erase.insert(x->second);
                st.erase(x);
            }
            for(auto c:to_erase){
                for(auto v:graph[c]){
                    graph[v].erase(c);
                    st.erase({degree[v],v});
                    degree[v]--;
                    degree[c]--;
                    if(to_erase.count(v)==0)
                        st.insert({degree[v],v});
                }
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}  
