#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<(i+j)%3<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  
