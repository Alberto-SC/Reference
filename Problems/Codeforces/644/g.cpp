#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b;
        if(n*a == b*m){
            vector<vector<int>> ans(n, vector<int>(m, 0));

            int shift;
            for (shift = 1; shift < m; shift++) 
                if (shift*n% m == 0) 
                    break;

            for (int i=0,dx=0;i<n;i++,dx+=shift) 
                for (int j=0;j<a;j++)
                    ans[i][(j+dx)%m] = 1;
                
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++) {

                for(int j= 0;j<m;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}