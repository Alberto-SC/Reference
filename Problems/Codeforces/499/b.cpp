#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<int> nums(m);
        vector<int> b(101);
        for(int i = 0;i<m;i++){
            int x;cin>>x;
            b[x]++;
        }
        int mx = 0;
        for(int i = 1;i<=100;i++){
            int cont = 0;
            for(int j = 0;j<=100;j++){
                cont += b[j]/i;
            }
            if(cont>=n)mx = max(mx,i);
        }
        cout<<mx<<endl;
        
    }
    return 0;
}  

