#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        string A = "",B = "",C = "";
        for(int i = 1;i<n-1;i++){
            for(int j = i;j<n-1;j++){
                string a = s.substr(0,i);
                string b = s.substr(i,(j-i)+1);
                string c = s.substr(j+1);
                if((b<=a && b<=c) || (a<=b && c<=b)){
                    A = a;
                    B = b;
                    C = c;
                }
            }
        }
        if(A =="")cout<<":("<<endl;
        else 
            cout<<A<<" "<<B<<" "<<C<<endl;
    }
    return 0;
}