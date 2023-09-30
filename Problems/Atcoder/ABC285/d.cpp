#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> inDegree(maxn,0);

void add_edge(int u,int v){
	inDegree[v]++;
	graph[u].push_back(v);
}
vector<int> topoSort(int n){
	vector<int> ans;
	queue<int> q;
	for(int i = 0;i<n;i++)
		if(inDegree[i] == 0)
			q.push(i);	
	
	while(!q.empty()){
		int u = q.front(); 
		q.pop();
		ans.push_back(u);
		for(auto v:graph[u]){
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	return ans;
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        map<string,int> mp;
        int key = 0;
        string s,t;
        for(int i = 0;i<n;i++){
            cin>>s>>t;
            if(mp.count(s)==0)
                mp[s] = key++;
            if(mp.count(t)==0)
                mp[t] = key++;
            add_edge(mp[s],mp[t]);
        }

        auto ans = topoSort(key);
        if(ans.size()==key)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}