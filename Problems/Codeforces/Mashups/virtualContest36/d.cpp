#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<string> M(n);
        for(auto &c:M)cin>>c;
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            bool flag = false;
            for(int j = 0;j<n-1;j++){
                if(M[j].substr(0,i+1)>M[j+1].substr(0,i+1)){
                    ans++;
                    flag = true;
                    break;
                }
            }
            if(flag){
                for(int j = 0;j<n;j++)
                    M[j][i] = '$';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
