#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	lli t,n;
    cin>>t;
    int mn = 30;
    while(t--){
        cin>>n;
        if(n>mn){
            cout<<"YES"<<endl;
            if(n == 36)
                cout<<"6 10 15 5"<<endl;
            else if(n == 40)
                cout<<"15 10 14 1"<<endl;
            else if(n == 44)
                cout<<"15 10 14 5"<<endl;
            else
                cout<<"6 10 14 "<<n-30<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}  