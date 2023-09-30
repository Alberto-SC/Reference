#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        stack<pair<char,int>> st;
        n  = s.size();
        vector<int> fr(n,-1);
        vector<int> b(26);
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first>s[i]){
                auto top = st.top();
                fr[top.second] = i;
                st.pop();
            }
            b[s[i]-'a']++;
            st.push({s[i],i});
        }
        stack<char> st2;
        int last = 0;
        for(int i = 0;i<n;i++){
            if(fr[i]==-1){
                b[s[i]-'a']--;
                cout<<s[i];
                while(last<26 && b[last]==0){
                    last++;
                }
                while(!st2.empty() && (st2.top()-'a')<=last){
                    cout<<st2.top();
                    st2.pop();
                }
            }
            else st2.push(s[i]),b[s[i]-'a']--;
        }
        while(!st2.empty()){
            cout<<st2.top();
            st2.pop();
        }
        cout<<endl;
    }
    return 0;
}  
