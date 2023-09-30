#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int>> pos(26);
        for(int i = 0;i<n;i++){
            pos[s[i]-'A'].push_back(i);            
        }
        bool flag = true;
        for(int i = 0;i<26;i++){
            for(int j = 1;j<pos[i].size();j++){
                if(pos[i][j]!= pos[i][j-1]+1)flag = false;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
