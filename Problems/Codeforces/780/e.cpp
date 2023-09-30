
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        char x;
        char matrix[3*n][3*n];
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>x;
                if(x=='1')ans++;
                int a= i,b = j;
                for(int k = 0;k<9;k++){
                    if(k == 3)a+=n,b = j;
                    if(k == 6)a+=n,b = j;
                    matrix[a][b] = x; 
                    b+=n;
                }
            }
        }
        // for(int i = 0;i<3*n;i++){
        //     for(int j = 0;j<3*n;j++){
        //         cout<<matrix[i][j]; 
        //     }
        //     cout<<endl;
        // }
        int N = 3*n,best = 0;
        for(int i= 0;i<=N-n;i++){
            int a = 0,b = i;
            int pref = 0;
            for(int j = 0;j<n;j++){
                pref+=matrix[a][b] == '1';
                a++,b++;
            }
            best = max(best,pref);
            while(a<N && b<N){
                pref-=matrix[a-n][b-n]== '1';
                pref+=matrix[a][b]== '1';
                a++,b++;
                best = max(best,pref);
            }
        }
        for(int i= 0;i<=N-n;i++){
            int a = i,b = 0;
            int pref = 0;
            for(int j = 0;j<n;j++){
                pref+=matrix[a][b] == '1';
                a++,b++;
            }
            best = max(best,pref);
            while(a<N && b<N){
                pref-=matrix[a-n][b-n] == '1';
                pref+=matrix[a][b] == '1';
                a++,b++;
                best = max(best,pref);
            }
        }
        cout<<(ans-best) + (n-best)<<endl;
    }
    return 0;
}  
