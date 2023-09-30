#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = false;
        for(int i = 1;i*i<=n;i++){
            if(n%i == 0){
                if(double(i)/(n/i)>=0.5)flag = true;
            }
        }
        if(flag)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}  

