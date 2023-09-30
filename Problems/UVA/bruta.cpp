#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


signed main(){__
    int t;
    cin>>t;
    while(t--){
        int q;
        string s,str;
        cin>>s;
        cin>>q;
        vector<string> S(q);    
        vector<bool> ans(q);
        for(int i = 0;i<q;i++)
            cin>>S[i];

        for(int i = 0;i<q;i++){
            bool flag = false;
            for(int j = 0;j<=s.size()-S[i].size();j++){
                int idx = 0;
                while(idx<S[i].size() && S[i][idx]== s[j+idx]){idx++;}
                if(idx==S[i].size()){
                    flag = true;
                    break;
                }
            }
            if(flag)cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }

    }
    return 0;
}