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
        string t = "hello";
        n = s.size();
        int l = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== t[l])l++;
            if(l==t.size())break;
        }
        bool flag = l==t.size();
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
