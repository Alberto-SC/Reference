#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,a,b,x;
    while(t--){
        cin>>a>>b>>x;
        vector<int> bk(10);
        for(int i = a;i<=b;i++){
            int aux = i;
            while(aux){
                bk[aux%10]++;
                aux/=10;
            }
        }
        cout<<bk[x]<<endl;
    }
    return 0;
}

'5' = 76
'0' = 71 
 
