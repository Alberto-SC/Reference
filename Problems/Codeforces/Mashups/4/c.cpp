#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n,k,d;
    while(t--){
        cin>>n>>k>>d;
        int x = 1;
        bool flag = false;
        for(int i = 0;i<d;i++){
            x*=k;
            if(x>=n){
                flag = true;
                break;
            }
        }
        if(!flag)cout<<-1<<endl;
        
        else{
            vector<vector<int>> ans;
            for(int i = 0;i<n;i++){
                int x = i;
                vector<int> b(d);
                int c = 0;
                while(x){
                    b[c++]=x%k;
                    x/=k;
                }
                reverse(b.begin(),b.end());
                ans.push_back(b);
            }
            for(int i = 0;i<d;i++)
                for(int j = 0;j<n;j++)
                    cout<<ans[j][i]+1<<" \n"[j==n-1];
        }
    }
    return 0;
}  
