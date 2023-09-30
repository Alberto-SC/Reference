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
        int x = n/3,a =0,b=0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(s[i]=='T'){
                a++;
            }
            if(s[i]=='M'){
                b++;
                if(a<b)flag = false;
            }
        }
        a = 0,b = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='T'){
                a++;
            }
            if(s[i]=='M'){
                b++;
                if(a<b)flag = false;
            }
        }
        if(a!= x*2 || b!= x)flag = false;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
