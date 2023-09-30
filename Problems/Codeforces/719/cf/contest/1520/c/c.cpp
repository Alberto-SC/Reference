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
        if(n==1)cout<<1<<endl;
        else if(n==2)
            cout<<-1<<endl;
        else{
            int p = 2;
            int im = 1;
            vector<vector<int>> m(n,vector<int>(n));
            for(int i = 0;i<n*n;i++){
                if(p>n*n)m[i/n][i%n] =im,im+=2;
                else m[i/n][i%n] =p,p+=2;
            }
            for(int i = 0;i<n;i++)
                for(int j = 0;j<n;j++)
                    cout<<m[i][j]<<" \n"[j ==n-1];
        }
    }
    return 0;
}  
