#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n == 4 || n == 2 || n == 1)cout<<-1<<endl;
        else if(n%3 == 0)
            cout<<n/3<<" 0 0"<<endl;
        else if(n%5 == 0)
            cout<<"0 "<<n/5<<" 0"<<endl;
        else if(n%7 == 0)
            cout<<"0 0 "<<n/7<<endl;
        else {
            if(n%3 == 2){
                cout<<(n-5)/3<<" "<<1<<" 0"<<endl;
            }
            else {
                cout<<(n-7)/3<<" "<<0<<" "<<1<<endl;
            }

        }
    }
    return 0;
}

