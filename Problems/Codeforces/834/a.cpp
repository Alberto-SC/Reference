#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    string t = "";
    for(int i= 0;i<30;i++)
        t+="Yes";

    while(T--){
        string s;
        cin>>s;
        int n = s.size();
        bool flag = true;
        if(s[0] == 'Y'){
            int id = 0;    
            for(int i = 0;i<n;i++){
                if(s[i]!=t[id++]){
                    flag = false;
                    break;
                }
            }
        }
        else if(s[0] =='e'){
            int id = 1;    
            for(int i = 0;i<n;i++){
                if(s[i]!=t[id++]){
                    flag = false;
                    break;
                }
            }
        }
        else if(s[0] =='s'){
            int id = 2;    
            for(int i = 0;i<n;i++){
                if(s[i]!=t[id++]){
                    flag = false;
                    break;
                }
            }
        }
        else 
            flag = false;
        
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}