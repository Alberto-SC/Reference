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
        vector<string> v(n);
        for(auto &c:v)cin>>c;
        int best = 0;
        for(int i = 0;i<5;i++){
            vector<pair<int,int>> A;
            for(int j = 0;j<n;j++){
                pair<int,int> p = {0,0};
                for(int k = 0;k<v[j].size();k++){
                    if(v[j][k]==char(i+'a'))p.first++;
                    else p.second++;
                }
                A.push_back(p);
            }
            sort(A.begin(),A.end(),[&](pair<int,int> a,pair<int,int> b){
                return (a.first-a.second)>(b.first-b.second);
            });
            int c1 = 0,c2=0;
            int ans = 0;
            for(int j = 0;j<n;j++){
                if(c1+A[j].first<=c2+A[j].second)
                    continue;
                c1+=A[j].first;
                c2+=A[j].second;
                ans++;
            }
            best = max(best,ans);
        }
        cout<<best<<endl;
    }
    return 0;
}  
