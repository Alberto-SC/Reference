#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli M = 2;
int F[100000+3];
lli f() {
	F[1] = 1%2;
    F[2] = 1%2;
    for(int i = 3;i<100000;i++)
        F[i] = (F[i-1]+F[i-2])%2; 
}
int main(){
    int ans = 1,n,t;
    f();
    cin>>t;
    while(t--){
        cin>>n;
        ans = 1;
        if(n == 1){cout<<0<<endl;continue;}
        else if(n == 2){cout<<0<<endl;continue;}
        for(int i = 1;i<=n-1;i++)
            if((F[i]+F[i+1])%2 == 1)ans++;
        cout<<2*ceil((n/3))+1<<endl;
    }
    return 0;
}