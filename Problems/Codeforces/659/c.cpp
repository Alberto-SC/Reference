#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s,t;
        cin>>s>>t;  
        bool flag = true;
        set<char> st[20];
        for(int i = 0;i<n;i++){
            if(s[i]!= t[i]){
                if(s[i]>t[i]){flag = false;break;}
                st[s[i]-'a'].insert(t[i]);
            }
        }
        if(!flag){cout<<-1<<endl;continue;}
        int ans = 0;
        vector<int> real(20);
        iota(real.begin(),real.end(),0);
        for(int i = 0;i<20;i++){
            if(st[real[i]].size()== 0)continue;
            ans++;
            char x = *st[real[i]].begin();
            for(auto c:st[i])
                if(c!= x)st[x-'a'].insert(c);
        }
        cout<<ans<<endl;
    }
    return 0;
}