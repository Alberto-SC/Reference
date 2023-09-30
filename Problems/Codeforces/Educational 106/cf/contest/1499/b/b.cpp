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
        string s1 = "",s2 = "";
        bool zero = true,one = true;
        int lastz ,firsto =-1;
        for(int i = 1;i<n;i++){
            if(s[i]== s[i-1] &&s[i]== '0')zero = false,lastz= i;
            if(s[i]== s[i-1] &&s[i]== '1'){
                one = false;
                if(firsto==-1)
                    firsto = i;
            }
        }
        if(zero || one){
            cout<<"YES"<<endl;
            continue;
        }
        zero = true;
        for(int i = firsto;i<n;i++){
            if(s[i]==s[i-1]&&s[i]=='0')zero = false;
        }
        one = true;
        for(int i = 1;i<lastz;i++)
            if(s[i]==s[i-1]&&s[i]=='1')one = false;

        if(zero&&one)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
