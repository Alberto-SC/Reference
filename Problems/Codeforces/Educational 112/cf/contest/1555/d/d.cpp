#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
int mods[3][3][maxn];
signed main(){__
	int t= 1,n,m,l,r;
    while(t--){
        cin>>n>>m;
        string s;
        cin>>s;
        vector<string> valids;
        for(int i = 0;i<n;i++){
            mods[s[i]-'a'][i%3][i] = 1;
        }        
        for(int i = 0;i<3;i++)
            for(int j = 0;j<3;j++)
                for(int k = 1;k<n;k++)
                    mods[i][j][k] = mods[i][j][k-1]+mods[i][j][k];
        
        for(int i = 0;i<m;i++){
            cin>>l>>r;
            l--,r--;
            vector<int> f = {0,1,2};    
            int L = (r-l)+1;
            int ans = L;
            do{
                int C = 0;
                // for(int k = 0;k<3;k++){
                //     for(int j = l;j<L;j++){
                //         cout<<mods[f[k]][k][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                for(int j = 0;j<3;j++){
                    C += mods[f[j]][j][r]-(l?mods[f[j]][j][l-1]:0);
                }        
                ans = min(ans,L-C);
            }while(next_permutation(f.begin(),f.end()));
            cout<<ans<<endl;
        }
    }
    return 0;
}  
