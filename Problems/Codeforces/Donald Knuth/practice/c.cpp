#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        string s;
        int x = 0;
        for(int i = 0;i<n;i++){
            cin>>s;
            if(s[1]=='+')x++;
            else x--;
        }
        cout<<x<<endl;
    }
    return 0;
}  
