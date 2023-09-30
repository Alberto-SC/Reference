#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,k,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> days(m);
        vector<int> order(m);
        iota(order.begin(),order.end(),0);
        for(int i = 0;i<m;i++){
            cin>>k;
            for(int j = 0;j<k;j++){
                cin>>x;
                days[i].push_back(x);
            }
        }   
        vector<int> cont(n+1);     bg
        vector<int> used(m);
        sort(order.begin(),order.end(),[&](int a,int b){
            return days[a].size()<days[b].size();
        });
        sort(days.begin(),days.end(),[&](vector<int> a,vector<int> b){
            return a.size()<b.size();
        });  
        
        for(int i = 0;i<m;i++){
            int mn =m*2,idx = 0;
            for(int j = 0;j<days[i].size();j++){
                if(cont[days[i][j]]<mn){
                    mn = cont[days[i][j]];
                    idx = j;
                }
            }
            cont[days[i][idx]]++;
            used[order[i]] = days[i][idx];
        }
        bool flag = true;
        // for(auto c:cont)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:used)cout<<c<<" ";
        // cout<<endl;
        for(int i = 1;i<=n;i++)
            if(cont[i]>(m+1)/2)flag = false;
        
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(auto c:used)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
