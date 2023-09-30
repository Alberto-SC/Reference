#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> c(n);
        vector<lli> a(n);
        vector<lli> b(n);
        for(auto &x:c)cin>>x;
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        lli ciclo = 0;
        lli mx = 0;
        for(lli i = 0;i<n-1;i++){
            if(i==0){
                ciclo+=abs(a[i+1]-b[i+1]);
            }
            else{
                ciclo+=(c[i]-1)-abs(a[i+1]-b[i+1]);
                mx = max(mx,ciclo+abs(a[i+1]-b[i+1]));
            }
            if(a[i+1]==b[i+1]){
                mx = max(mx,ciclo);
                ciclo = 2;
            }
            else{
                ciclo+=2;
            }
        }
        ciclo+=c[n-1]-1;
        mx = max(mx,ciclo);
        cout<<mx<<endl;
    }
    return 0;
}  

