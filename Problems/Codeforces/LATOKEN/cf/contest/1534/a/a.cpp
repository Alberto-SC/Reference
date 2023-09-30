#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> grid(n);
        for(int i = 0;i<n;i++){
            cin>>grid[i];
        }
        vector<string> ans1(n,string(m,'R'));
        vector<string> ans2(n,string(m,'W'));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i+j)&1)ans1[i][j] = 'R',ans2[i][j] ='W';
                else ans2[i][j] = 'R',ans1[i][j] ='W';
            }
        }
        bool flag1 = true,flag2 = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!= '.' &&grid[i][j]!= ans1[i][j])flag1 = false;
                if(grid[i][j]!= '.' &&grid[i][j]!= ans2[i][j])flag2 = false;
            }
        }
        if(flag1){
            cout<<"YES"<<endl;
            for(auto c:ans1)cout<<c<<endl;
        }
        else if(flag2){
            cout<<"YES"<<endl;
            for(auto c:ans2)cout<<c<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}  
