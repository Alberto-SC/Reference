#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int l = 0,idx =0,cont = 1;
        n = s.size(),m = t.size();
        set<char> st;
        for(int i = 0;i<t.size();i++)
            st.insert(t[i]);
        for(int i = 0;i<n;i++)
            st.erase(s[i]);
        if(st.size()){
            cout<<-1<<endl;
            continue;
        } 
        vector<int> pos[26];
        for(int i = 0;i<n;i++)
            pos[s[i]-'a'].push_back(i);
        int last =-1;
        for(int i = 0;i<m;i++){
            int a = t[i]-'a';
            int idx = lower_bound(pos[a].begin(),pos[a].end(),last+1)-pos[a].begin();
            if(idx==pos[a].size()|| pos[a][idx]<last){
                last = -1;
                int idx = lower_bound(pos[a].begin(),pos[a].end(),last+1)-pos[a].begin();
                cont++;
                last = pos[a][idx];
            }
            else
                last =pos[a][idx];
        }

        cout<<cont<<endl;
    }
    return 0;
}  
