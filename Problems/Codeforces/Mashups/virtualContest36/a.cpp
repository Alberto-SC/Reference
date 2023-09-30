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
        bool n9 = true;
        for(int i = 0;i<n;i++){
            if((s[i]-'0')!= 9)n9 = false;
            if((s[i]-'0')== 9 && n9){n9 = false;continue;}
            if((9-(s[i]-'0'))< (s[i]-'0'))s[i] = char((9-(s[i]-'0'))+'0');
        }
        int idx = 0;
        while(s[idx]=='0'){idx++;}
        if(idx==n)cout<<0<<endl;
        else 
            cout<<s.substr(idx)<<endl;
    }
    return 0;
}  
