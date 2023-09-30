#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m,k;
    while(t--){
        cin>>n>>m>>k;
        int cont = 0;
        for(int i = 0;i<n;i++){
            int time = 0,x,q;
            for(int j = 0;j<k;j++){
                cin>>x;
                time+=x;
            }
            cin>>q;
            if(time>=m && q<=10)cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}  

