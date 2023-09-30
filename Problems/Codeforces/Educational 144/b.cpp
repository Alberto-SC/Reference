#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';
#define int long long
using namespace std;


signed main(){__
    int T;
    cin>>T;
    while(T--){
        string a,b;
        cin>>a>>b;
        if(a[0]== b[0]){
            cout<<"YES"<<endl;
            cout<<a[0]<<"*"<<endl;
        }
        else if(a.back()==b.back()){
            cout<<"YES"<<endl;
            cout<<"*"<<a.back()<<endl;
        }
        else{
            set<string> st1;
            set<string> st2;
            int n = a.size();
            int m = b.size();
            for(int i = 0;i<n-1;i++)
                st1.insert(a.substr(i,2));
            
            for(int i = 0;i<m-1;i++)
                st2.insert(b.substr(i,2));
 

            string ans = "";
            for(auto c:st1){
                if(st2.count(c))ans = c;
            }
            if(ans != ""){
                ans = "*"+ans+"*";
                cout<<"YES"<<endl;
                cout<<ans<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

