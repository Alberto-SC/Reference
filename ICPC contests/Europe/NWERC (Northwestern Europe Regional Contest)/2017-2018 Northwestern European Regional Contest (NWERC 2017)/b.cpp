#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        if(n == 1|| n ==2 || n == 3)cout<<1<<endl;
        else cout<<n-2<<endl;
    }
    return 0;
}  

