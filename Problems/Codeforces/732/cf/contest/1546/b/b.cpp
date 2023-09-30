#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> a(n);
        vector<string> b(n-1);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        string ans ="";
        for(int i = 0;i<m;i++){
            string s1 = "",s2 = "";
            for(int j = 0;j<n;j++)
                s1+=a[j][i];    
            for(int j = 0;j<n-1;j++)
                s2+=b[j][i];
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            for(int j = 0;j<n-1;j++)
                if(s1[j]!=s2[j]){
                    ans.push_back(s1[j]);
                    break;
                }
            if(ans.size()!= i+1)
                ans.push_back(s1.back());            
        }
        cout<<ans<<endl;
    }
    return 0;
}  
