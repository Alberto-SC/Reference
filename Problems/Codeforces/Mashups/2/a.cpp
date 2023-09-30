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
        int h = 1,w = 1;
        for(int i = 0;i<n;i++){
            cin>>s;
            if(s== "DR"|| s=="UL")
                h++;
            else if(s== "DL"|| s=="UR")
                w++;
            else 
                h++,w++;
        }
        cout<<h*w<<endl;
    }
    return 0;
}  
