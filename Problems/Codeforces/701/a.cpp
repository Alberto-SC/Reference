#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int logbase(int a,int b){
    return log(a*1.0)/log(b*1.0);
}
int main(){__
	int t= 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int mn = a+1;
        int flag = 0;
        if(b==1){
            flag = 1;
            b++;
        }
        for(int i = b;i<=b+logbase(a,b)+1;i++){
            int aux = a;
            int cont = 0;
            while(aux){
                aux/=i;
                cont++;
            }
            cont+=flag;
            flag++;
            // cout<<cont<<endl;
            mn = min(cont,mn);
        }
        cout<<mn<<endl;
    }
    return 0;
}  

