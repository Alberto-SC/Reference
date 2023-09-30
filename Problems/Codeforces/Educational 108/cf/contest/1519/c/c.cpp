#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        int ans = 0;
        for(auto &c:b)cin>>c,ans+=c;
        vector<vector<int>> u(n+1);
        for(int i = 0;i<n;i++){
            u[a[i]].push_back(b[i]);
        }
        
        vector<vector<int>> uu;
        for(int i = 0;i<=n;i++){
            if(u[i].size()){
                sort(u[i].rbegin(),u[i].rend());
                for(int j = 1;j<u[i].size();j++){
                    u[i][j] = u[i][j]+u[i][j-1];
                }
                uu.push_back(u[i]);
            }
        }
        sort(uu.begin(),uu.end(),[&](vector<int> a,vector<int> b){
            return a.size()<b.size();
        });
        int j = 0;
        int nosirven = 0;
        for(int i = 1;i<=n;i++){
            while(j<uu.size() &&uu[j].size()<i){
                nosirven +=uu[j].back();
                j++;
            }
            int res = 0;
            for(int k = j;k<uu.size();k++){
                int mod = uu[k].size()%i;
                res += uu[k].back()-uu[k][uu[k].size()-1-mod];
            }
            cout<<ans-res-nosirven<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
