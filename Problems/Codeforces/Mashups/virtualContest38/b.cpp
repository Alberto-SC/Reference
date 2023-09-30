#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        vector<char> c ={'R','G','B'};
        map<char,int>mp;
        mp['R'] = 0;
        mp['G'] = 1;
        mp['B'] = 2;
        int cont = 0;
        for(int i = 1;i<n;i++){
            if(s[i]== s[i-1]){
                if(i+1>=n)
                    s[i] = c[(mp[s[i]]+1)%3];
                else if(i<n){
                    if(c[(mp[s[i]]+1)%3] == s[i+1])
                        s[i] = c[(mp[s[i]]+2)%3];
                    else
                        s[i] = c[(mp[s[i]]+1)%3];
                }
                cont++;
            }
        }
        cout<<cont<<endl;
        cout<<s<<endl;
    }
    return 0;
}  
