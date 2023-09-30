#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        bool flag = false;
        for(int i = 0;i<n-1;i++){
            if(s[i]== '1' && s[i+1]=='0')
                flag = true;
        }
        if(s == "1010" ||!flag)
            cout<<"Bob"<<endl;        
        else 
            cout<<"Alice"<<endl;
    }
    return 0;
}  
