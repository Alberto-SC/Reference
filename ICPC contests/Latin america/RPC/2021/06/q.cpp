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
        int x = n/3;
        vector<string> vs;
        int y = 1;
        string t = "";
        for(int i = 0;i<n;i++){
            t+=s[i];
            if(i+1 == x*y){
                vs.push_back(t);
                t= "";
                y++;
            }
        }
        sort(vs.begin(),vs.end());
        cout<<vs[1]<<endl;
    }
    return 0;
}  
