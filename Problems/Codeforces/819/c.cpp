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
        stack<char> st;
        int id = 0;
        char last = '(';
        for(int i= 0;i<2*n;i++){
            if(s[i]=='('){
                if(last==s[i])
                    id++;
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            last = s[i];
        }
        cout<<id<<endl;
    }
    return 0;
}