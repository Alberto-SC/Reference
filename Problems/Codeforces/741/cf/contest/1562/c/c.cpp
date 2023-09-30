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
        int pos = -1;
        for(int i = 0;i<n;i++)
            if(s[i]=='0')pos = i;
        if(pos==-1){
            if(n&1)
                cout<<1<<" "<<n-1<<" "<<1<<" "<<n/2 <<endl;
            else
                cout<<1<<" "<<n<<" "<<1<<" "<<n/2<<endl;
        }
        else{
            if(pos+1<=n/2){
                cout<<pos+1<<" "<<n<<" "<<pos+2<<" "<<n<<endl;
            }
            else{
                cout<<1<<" "<<pos+1<<" "<<1<<" "<<pos<<endl;
            }
        }
    }
    return 0;
}  
