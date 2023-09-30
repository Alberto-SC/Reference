#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> nw(26);
        iota(nw.begin(),nw.end(),0);        
        int first =-1;
        int mx  =0;
        for(int i = 0;i<n;i++){
            if(s[i]-'a'<=k){
                nw[s[i]-'a'] = 0;
                mx = max(mx,(int)s[i]-'a');
            }
            else{
                first = i;
                break;
            }
        }
        if(first==0){
            iota(nw.begin(),nw.end(),0);
            int nxt = (s[0]-'a')-k;
            for(int i = (s[0]-'a');i>=nxt;i--){
                nw[i] = nxt;
            }
        }   
        else if(first!=-1){
            for(int i = mx;i>=0;i--){
                nw[i] = 0;
            }
            k-=mx;
            int nxt = (s[first]-'a')-k;
            for(int i = (s[first]-'a');i>=nxt;i--){
                nw[i] = nxt;
            }
        }

        for(int i = 0;i<n;i++){
            cout<<char(nw[s[i]-'a']+'a');
        }
        cout<<endl;
    }
    return 0;
}