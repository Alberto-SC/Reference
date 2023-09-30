#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();

        if(s.size()== 1&&s== "a"){
            cout<<"NO"<<endl;
            continue;
        }
        int i = -1;
        for(i = 0;i<n;i++){
            if(s[(n-1)-i]!= 'a')
            break;
        }
        if(i ==-1 || i ==n){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
            cout<<s.substr(0,i);
            cout<<'a';
            cout<<s.substr(i);
            cout<<endl;
        }
    }
    return 0;
}  
