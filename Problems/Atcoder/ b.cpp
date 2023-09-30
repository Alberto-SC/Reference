#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,y,z;
    while(T--){
        cin>>n>>x>>y>>z;
        vector<pair<pair<int,int>,int>> v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i].first.first;
            v[i].second = i;
        }
        for(int i = 0;i<n;i++){
            cin>>v[i].first.second;
        }
        sort(v.begin(),v.end(),[&](pair<pair<int,int>,int> a ,pair<pair<int,int>,int> b){
            if(a.first.first== b.first.first)return a.second<b.second;
            return a.first.first>b.first.first;
        });
        vector<int> ans;
        for(int i = 0;i<x;i++){
            ans.push_back(v[i].second+1);
        }
        vector<pair<pair<int,int>,int>> A;
        for(int i= x;i<n;i++){
            A.push_back(v[i]);
        }

        sort(A.begin(),A.end(),[&](pair<pair<int,int>,int> a ,pair<pair<int,int>,int> b){
            if(a.first.second== b.first.second)return a.second<b.second;
            return a.first.second>b.first.second;
        });
    
        for(int i = 0;i<y;i++){
            ans.push_back(A[i].second+1);
        }
        vector<pair<int,int>> B;
        for(int i= y;i<A.size();i++){
            B.push_back({A[i].first.first+A[i].first.second,A[i].second});
        }

        sort(B.begin(),B.end(),[&](pair<int,int> a ,pair<int,int> b){
            if(a.first== b.first)return a.second<b.second;
            return a.first>b.first;
        });

        for(int i = 0;i<z;i++){
            ans.push_back(B[i].second+1);
        }

        sort(ans.begin(),ans.end());

        for(auto c:ans)cout<<c<<endl;
    }
    return 0;
}