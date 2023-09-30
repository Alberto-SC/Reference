#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,x,k,y;
    while(t--){
        cin>>n>>m;
        cin>>x>>k>>y;
        vector<int> a(n);
        vector<int> b(m);        
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;  
        vector<int> ids;
        bool flag = true;
        int l = 0;
        for(int i = 0;i<m;i++){
            while(l<n && a[l]!= b[i]){
                cout<<a[l]<<" "<<b[i]<<endl;
                l++;
            }
            cout<<l<<endl;
            if(l==n){
                flag = false;
                break;
            }
            ids.push_back(l);    
            l++;
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0;i<m;i++){
             
        }
        for(auto c:ids)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
