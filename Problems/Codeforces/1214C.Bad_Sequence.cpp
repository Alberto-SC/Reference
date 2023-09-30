#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    int cont = 0;
    int o = 0,c = 0;
    for(int i = 0;i<n;i++){
        if(s[i]== ')' && !st.empty())st.pop();
        else if(s[i]== ')' && st.empty())cont++;
        if(s[i]== '(')st.push('('),o++;
        if(s[i]== ')')c++;
    }
    if(o !=c)return cout<<"NO"<<endl,0;
    // cout<<cont<<" "<<st.empty()<<endl;
    if(!st.empty() && cont==1)cout<<"YES"<<endl;
    else if(st.empty() && cont == 0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}