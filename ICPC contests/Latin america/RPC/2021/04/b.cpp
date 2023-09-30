#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<string> ans(n);
        for(int i = 0;i<n;i++)
            cin>>ans[i];
        int res = 0,num;
        for(int i = 0;i<(1<<m);i++){
            vector<int> p(n);
            for(int j = 0;j<m;j++){
                for(int k = 0;k<n;k++){
                    if((i>>j)&1 && ans[k][j]== 'T')p[k]++;
                    else if(!((i>>j)&1) && ans[k][j] == 'F')p[k]++;
                }
            }
            int mn = *min_element(p.begin(),p.end());
            if(mn >res){
                res = mn;
                num = i;
            }
        }
        cout<<res<<endl;
    }   
    return 0;
}  
