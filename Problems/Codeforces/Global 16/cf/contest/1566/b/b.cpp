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
        int z = 0;
        n = s.size();
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && s[i]==s[j]){
                j++;
            }
            if(s[i]=='0')
                z++;
            i = j;
        }   
        z = min(z,2ll);
        cout<<z<<endl;
    }
    return 0;
}  
