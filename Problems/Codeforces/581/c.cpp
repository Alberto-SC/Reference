#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n;
        vector<string> graph(n);
        for(auto &c:graph)cin>>c;
        cin>>m;
        vector<int> path(m);
        for(auto &c:path)cin>>c;
        vector<int> spath;
        spath.push_back(path[0]);
        vector<bool> vis(n);
        auto f = [&](int u){
            for(int i = 0;i<n;i++)
                if(vis[i]&& graph[i][u]=='1')return true;
            return false;
        };
        int idx = 1;
        int last = 0;
        while(idx<m){
            if(idx>1)vis[path[idx-2]-1] =true;
            if(f(path[idx]-1) ||path[idx] == spath.back() ){
                spath.push_back(path[idx-1]);
                for(int i = last;i<=idx-2;i++){
                    vis[path[i]-1] = false;
                }
                last = idx;
            } 
            idx++;
        }
        spath.push_back(path[m-1]);
        cout<<spath.size()<<endl;
        for(auto c:spath)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

