#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> sz(maxn);
int n;
int c1= -1,c2 = -1;
void find_centroid(int u,int p = -1){
    sz[u] = 1;
    bool centroid = true;
    for(auto v:graph[u]){
        if(v ==p)continue;
        find_centroid(v,u);
        sz[u]+=sz[v];
        if(sz[v]>n/2)centroid = false;
    }
    if(n-sz[u]>n/2)centroid = false;
    if(centroid){
        if(c1 != -1)c2 = u;
        else c1 = u;
    }
} 


int main(){__
	int t= 1,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        pair<int,int> dummy;
        for(int i = 0;i<n;i++)
            graph[i].clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            dummy = {u,v};
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        c1 = -1,c2 = -1;
        find_centroid(0);
        if(c2 == -1){
            cout<<dummy.first+1<<" "<<dummy.second+1<<endl;
            cout<<dummy.first+1<<" "<<dummy.second+1<<endl;
        }
        else{
            for(auto v:graph[c1]){
                if(v!= c2){
                    cout<<c1+1<<" "<<v+1<<endl;
                    cout<<c2+1<<" "<<v+1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}  

