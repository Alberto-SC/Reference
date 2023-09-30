#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> values(n);
        vector<int> degree(n);
        for(auto &c:values)cin>>c;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            degree[u]++;
            degree[v]++;
        }
        priority_queue<pair<int,int>> q;
        lli last =0;
        for(int i = 0;i<n;i++){
            if(degree[i]>1){
                q.push({values[i],degree[i]-1});
            }
            last+=values[i];
        }
        int idx = 0;
        while(idx<n-1 && !q.empty()){
            cout<<last<<" ";
            auto x = q.top();
            x.second--;
            last+=x.first;
            q.pop();
            if(x.second>0){
                q.push(x);
            }
            idx++;
        }
        if(idx<n-1){
            for(int i =idx;i<n-1;i++)
                cout<<last<<" ";
        }
        cout<<endl;
    }
    return 0;
}  

