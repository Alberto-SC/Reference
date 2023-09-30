#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n<k)cout<<k-n<<endl;
        else {
            int mod = n%k;

            if(mod == 0)cout<<0<<endl;
            else
                cout<<k-mod<<endl;
        }
    }
    return 0;
}  

