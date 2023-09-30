#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli combina(int n,int m){ 
	int i,j;
	lli bc[n][m];
	for (i=0; i<=n; i++) bc[i][0] = 1;
	for (j=0; j<=n; j++) bc[j][j] = 1;
	for (i=1; i<=n; i++)
	    for (j=1; j<i; j++)
	        bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return bc[n][m];
}

int main(){
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int digitsa = log10(a);
        int digitsb = log10(b);
        int ansa = 0,ansb;
        if(a<1000)
            ansa = a+1;
        else {
            for(int i = 0;i<digitsa-3;i++)
                ansa+=combina(i,digitsa);
            
        }
        for(int i = 0;i<digitsb-3;i++)
            ansb+=combina(i,digitsb);
        cout<<((b-a)+1)-(ansb-ansa)<<endl;
    }
    return 0;
}