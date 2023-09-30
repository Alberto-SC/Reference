#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s,t;
        cin>>s>>t;
        if(t.size()<s.size()){
            cout<<-1<<endl;
            continue;
        }
        if(s==t){
            cout<<0<<endl;
        }
        int idx1 = s.size()-1,idx2 = t.size()-1;
        string ans = "";
        bool flag = true;
        
        while(idx1>=0){
            if(idx2<0){
                flag = false;
                break;
            }
            if(s[idx1]<=t[idx2]){
                char x= (t[idx2]-'0')-(s[idx1]-'0');
                ans+=char(x+'0');
                idx1--;
                idx2--;
            }
            else {
                if(idx2-1<0){
                    flag = false;
                    break;
                }
                int y = ((t[idx2-1]-'0')*10)+(t[idx2]-'0');
                int x = y-(s[idx1]-'0');
                if(x>9|| x<=0){
                    flag = false;
                    break;
                }
                idx1--;
                idx2-=2;
                ans+=char(x+'0');
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        while(idx2>=0){
            ans.push_back(t[idx2]);
            idx2--;
        }
        while(ans.size() &&ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}