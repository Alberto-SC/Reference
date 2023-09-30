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
        int n = s.size();
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        int idx = 1;
        while(idx <n && s[idx]>=s[idx-1]){
            idx++;
        }

        char mn = s[idx];
        bool f = false;
        for(int i = idx+1;i<n;i++){
            if(s[i]>mn){
                s[i] = mn;
                f = true;
            }
            else{
                if(f)
                    s[i] = mn;
                else
                    mn = s[i];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}  
