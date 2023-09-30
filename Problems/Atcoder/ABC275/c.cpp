#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int k = 3;
signed main(){__
    int T = 1,n;
    while(T--){
        vector<string> M(9);
        for(auto &c:M)cin>>c;
        n = 9;
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int x = 0;x<=i;x++){
                    for(int y = j+1;y<n;y++){
                        int cont = 0;
                        int a = i;
                        int b = j;
                        int dx = abs(x-i);
                        int dy = abs(y-j);    
                        cont+=M[a][b]=='#';
                        a-=dx;
                        b+=dy;
                        if(a>=n || b>=n || a<0 || b<0)break;
                        cont+=M[a][b]=='#';
                        a+=dy;
                        b+=dx;
                        if(a>=n || b>=n || a<0 || b<0)break;
                        cont+=M[a][b]=='#';
                        a+=dx;
                        b-=dy;
                        if(a>=n || b>=n || a<0 || b<0)break;
                        cont+=M[a][b]=='#';
                        if(cont==4)ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
