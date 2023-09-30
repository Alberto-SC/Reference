#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int check(string s){ 
    stack<char> st;
    int bad = 0; 
    for (int i=0; i<s.size(); i++){ 
        if (s[i]=='(') { 
            st.push(s[i]); 
            continue; 
        } 
        if(!st.empty())
            st.pop(); 
        else if(st.empty()) bad++;
    } 
    return bad; 
}
int main(){
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        cout<<check(s)<<endl;
    }
    return 0;
}