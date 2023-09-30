#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n == 1){
            cout<<"1 4 3 2"<<endl;
        }
        else if(n == 2){
            cout<<"2 4 3 1"<<endl;
        }
        else if (n == 0) {
            cout<<"1 3 4 5"<<endl;
        }
        else if(n == 3){
            cout<<"1 3 5 6"<<endl;
        }
        else{
            cout<<"1 2 3 "<<(n^3)<<endl;
        }
    }

}
