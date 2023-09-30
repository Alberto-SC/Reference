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
        int mn = abs((s[0]-'a')-(s.back()-'a'));
        int l = min(s[0]-'a',s.back()-'a');
        int r = max(s[0]-'a',s.back()-'a');
        vector<int> ans = {1};
        for(int i = 1;i<n-1;i++){
            if((s[i]-'a')>=l && (s[i]-'a')<=r){
                ans.push_back(i+1);
            }
        }
        ans.push_back(n);
        if(s.back()>s[0]){
            sort(ans.begin(),ans.end(),[&](int a,int b){
                if(s[a-1]==s[b-1])return a<b;
                return s[a-1]<s[b-1];
            });
        }
        else{
            sort(ans.begin(),ans.end(),[&](int a,int b){
                if(s[a-1]==s[b-1])return a<b;
                return s[a-1]>s[b-1];
            });
        }
        cout<<mn<<" "<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}