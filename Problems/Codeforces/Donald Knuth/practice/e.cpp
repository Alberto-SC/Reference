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
        cin>>s;
        vector<int>b(26);
        for(int i = 0;i<n;i++)
            b[s[i]-'a']++;
        for(int i = 0;i<26;i++)
            for(int j = 0;j<b[i];j++)
                cout<<(char(i+'a'));
        cout<<endl;
    }
    return 0;
}  
