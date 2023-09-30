#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int cont = 0;
        bool flag = false;
        for(int i = 1;i<=n;i++){
            if(s[i-1]=='1')cont++;
            if(cont>=(i+1)/2)flag = true;
        }
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
