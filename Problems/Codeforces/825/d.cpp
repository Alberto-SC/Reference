#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        n*=2;
        int c1 = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1')c1++;
        }
        if(c1&1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> bad;
        for(int i = 0;i<n;i+=2){
            if(s[i]!=s[i+1]){
                if(bad.size()&1)bad.push_back(i);
                else bad.push_back(i+1);
            }
        }
        cout<<bad.size()<<" ";
        for(auto c:bad)cout<<c+1<<" ";
        cout<<endl;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(i&1)
                ans.push_back(i);
        }
        for(auto c:ans)cout<<c+1<<" ";
        cout<<endl;
    }
    return 0;
}