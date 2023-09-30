#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s,t1;
        cin>>s>>t1;
        vector<int>f(3);
        sort(s.begin(),s.end());
        for(int i = 0;i<s.size();i++){
            if(s[i]-'a'<3)f[s[i]-'a']++;
        }
        string t2 = t1;
        int cont = 0;
        if(t1 == "abc" &&f[0]&&f[1] && f[2])t2 = "acb";
        else t2 = "abc";
        for(int i = 0;i<3;i++){
            for(int j = 0;j<f[t2[i]-'a'];j++)
                cout<<t2[i],cont++;
        }
        for(int i = cont;i<s.size();i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}  
