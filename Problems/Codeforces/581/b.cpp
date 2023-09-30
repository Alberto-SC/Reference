#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,l,r;
    while(t--){
        cin>>n>>l>>r;
        int mn = (1<<l)-1;
        mn+=(n-l);
        int mx = (1<<r)-1;
        mx+= (1<<(r-1))*(n-r);
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}  

