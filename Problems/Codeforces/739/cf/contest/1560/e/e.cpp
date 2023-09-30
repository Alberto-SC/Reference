#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<char> st;
        string order;
        n = s.size();
        for(int i = n-1;i>=0;i--){
            if(!st.count(s[i])){
                order+= s[i];
                st.insert(s[i]);
            }   
        }
        reverse(order.begin(),order.end());
        vector<int> b1(26);
        for(int i = 0;i<n;i++)
            b1[s[i]-'a']++;
        vector<int> pos(26);
        for(int i = 0;i<order.size();i++)
            pos[order[i]-'a'] = i;
        vector<int> b2(26);
        bool flag =  true;
        for(int i = 0;i<26;i++){
            if(b2[i]%(pos[i]+1))
                flag = false;
            b2[i] = b1[i]/(pos[i]+1);
        }
        // cout<<flag<<endl;
        // for(auto c:st){
        //     cout<<c<<" "<<b2[c-'a']<<" "<<b1[c-'a']<<endl;
        // }
    
        string ans;
        for(int i = 0;i<n;i++){
            ans+=s[i];
            bool f = true;
            b2[s[i]-'a']--;
            for(int j = 0;j<26;j++){
                if(b2[j])f = false;
            }
            if(f)break;
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }

        string t;
        st.clear();
        for(int i = 0;i<order.size();i++){
            for(int j = 0;j<ans.size();j++){
                if(!st.count(s[j]))
                    t+=s[j];
            }
            st.insert(order[i]);
        }
        if(t!=s){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<" "<<order<<endl;
    }
    return 0;
}  
