#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<vector<int>> M(n,vector<int> (n));
    for(auto &c:M)for(auto &d:c)cin>>d;
    vector<int> a(n),b(n); 
    for(int i = 0;i<n;i++)
        a[i] = *min_element(M[i].begin(),M[i].end());
    
    vector<int> diff(n-1);
    bool flag = true;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<n;j++){
            if(i && M[i][j]-M[i][j-1]!= diff[j-1])flag = false;
            diff[j-1] = M[i][j]-M[i][j-1];
        }
    }

    if(!flag)return cout<<"No"<<endl,0;
    
    vector<int> c(n);
    for(int i = 0;i<n;i++)
        c[i] = M[i][0]-a[i];
    int mx = *max_element(c.begin(),c.end());
    for(int i = 0;i<n;i++)
        a[i]-=(mx-c[i]);

    for(int i = 0;i<n;i++)
        b[i] = M[0][i]-a[0];
    cout<<"Yes"<<endl;
    for(auto c:a)cout<<c<<" ";
    cout<<endl;
    for(auto c:b)cout<<c<<" ";
    cout<<endl;
    

    return 0;
}  
