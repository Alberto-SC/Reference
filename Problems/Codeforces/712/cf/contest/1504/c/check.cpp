#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    string s;
    int n;
    cin>>s;
    n = s.size();
    stack<char> st;
    bool flag = true;
    for(int i = 0;i<n;i++){
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')' &&!st.empty())st.pop();
        else if(s[i]==')' &&st.empty()){
            flag = false;
            break;
        }
    }
    if(!st.empty())
        cout<<"NO"<<endl;
    else if(!flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}