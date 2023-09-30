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
        vector<string> s(3);
        string a,b;
        cin>>s[0]>>s[1]>>s[2]; 
        int mx = 0;

        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i ==j)continue;
                int l = 0;
                for(int k = 0;k<2*n;k++){
                    if(s[i][k] == s[j][l])l++;
                }
                if(l>mx){
                    mx = l;
                    a = s[i];
                    b = s[j];
                }
            }
        }
        string ans(3*n,'a');
        for(int i = 0;i<2*n;i++)
            ans[i]=  a[i];
        for(int j = 2*n;j<3*n;j++){
            if(mx<2*n)
                ans[j] = b[mx++];
            else ans[j] = '0';
        }
        cout<<ans<<endl;
    }
    return 0;
}  
