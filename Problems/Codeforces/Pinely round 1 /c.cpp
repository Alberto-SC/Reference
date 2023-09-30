#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> graph[107];

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> inDegree(n);
        for(int i = 0;i<n;i++){
            graph[i].clear();
            for(int j = 0;j<n;j++){
                char c;
                cin>>c;
                if(c == '1'){
                    graph[i].push_back(j);
                    inDegree[j]++;
                }
            }
        }
        queue<int> q; 
        int id = 1;
        vector<int> d(n);   
        set<int> ans[107];

        for(int i = 0;i<n;i++){
            if(inDegree[i] ==0){
                q.push(i);
                d[i] = 0;
                // ans[i].insert(id++);
            }
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            // if(ans[u].size()<=d[u]){
            ans[u].insert(id++);
            // }
            for(auto v:graph[u]){
                for(auto c:ans[u]){
                    ans[v].insert(c);
                }
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                    d[v] = d[u]+1;
                }
            }
        }

        for(int i= 0;i<n;i++){
            cout<<ans[i].size()<<" ";
            for(auto c:ans[i])cout<<c<<" ";
            cout<<endl;
        }

    }
    return 0;
}