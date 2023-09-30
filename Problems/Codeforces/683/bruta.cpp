
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int lcs(string X, string Y){
    int m = X.size();
    int n = Y.size();  
    int L[m+1][n+1];
    for (int i = 0; i <= m; i++)  {  
        for (int j = 0; j <= n; j++)  {  
            if (i == 0 || j == 0)  
                L[i][j] = 0;  
            else if (X[i - 1] == Y[j - 1])  
                L[i][j] = L[i - 1][j - 1] + 1;  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];
}  
  
int main(){
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        vector<string> ss;
        vector<string> st;
        for(int i = 0;i<n;i++){ 
                for(int j = i+1;j<=n;j++){
                ss.push_back(s.substr(i,j-i));
            }   
        }     
        for(int i = 0;i<m;i++){ 
                for(int j = i+1;j<=m;j++){
                st.push_back(t.substr(i,j-i));
            }   
        }     
        // for(auto c:ss)
        //     cout<<c<<endl;
        // cout<<endl;
        // for(auto c:st)
        //     cout<<c<<endl;
        // cout<<endl;
        int ans = 0;
        for(auto c:ss){
            for(auto d:st){
                int lc = lcs(c,d);
                int x = (4*lc) -(c.size()+d.size());
                if(x>ans){
                    cout<<c<<endl<<d<<endl;
                    cout<<lc<<endl;
                }
                ans = max(x,ans);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}  

