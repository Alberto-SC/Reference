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
        k--;
        int x = n/2;
        int init = 1;
        if(n&1){
            int y = k/x;
            // cout<<y<<endl;
            init+=((x+1)*y);
            init+= k%x;
            if(init%n ==0)cout<<n<<endl;
            else
            cout<<(init%n)<<endl;
        }
        else {
            init+=k;
            if(init%n ==0)cout<<n<<endl;
            else
                cout<<(init%n)<<endl;
        }
    }
    return 0;
}  

