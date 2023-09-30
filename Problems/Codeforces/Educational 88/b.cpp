#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        vector<string> s(n);
        for(int i = 0;i<n;i++)
            cin>>s[i];
        int ans = 0;
        if(y> x*2){
            for(int i= 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(s[i][j] == '.' )ans+=x;
                }
            }
        }
        else{
            for(int i= 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(s[i][j] == '.' && j+1<m && s[i][j+1] == '.')ans+=y,j++;
                    else if(s[i][j] == '.') ans+=x;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}