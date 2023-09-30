#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        string a(n,'?'),b(n,'?');
        bool flag = true,yes = false;
        int cont = 0;
        for(int mask = 0;mask<(1<<n);mask++){
            int aux = mask;
            for(int j = 0;j<n;j++){
                if((aux>>j)&1)
                    a[j] ='(';
                else 
                    a[j] =')';
            }
            for(int j = 0;j<n;j++){
                if(s[j]== '1')b[j] = a[j];
                else if(a[j]==')')b[j]= '(';
                else b[j]= ')';
            }
            stack<char> st;
            bool flag = true;
            for(int i = 0;i<n;i++){
                if(b[i]=='(')st.push(b[i]);
                else if(b[i]==')' &&!st.empty())st.pop();
                else if(b[i]==')' &&st.empty()){
                    flag = false;
                    break;
                }
            }
            if(!st.empty())continue;
            if(!flag)continue;
            for(int i = 0;i<n;i++){
                if(a[i]=='(')st.push(a[i]);
                else if(a[i]==')' &&!st.empty())st.pop();
                else if(a[i]==')' &&st.empty()){
                    flag = false;
                    break;
                }
            }
            if(flag && st.empty()){
                yes = true;
                cont++;
                break;
            }

        }
        // cout<<cont<<endl;
        if(!yes){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
        }
    }
    return 0;
}  
