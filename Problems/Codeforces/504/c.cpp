#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<bool> used(n,false);
    int open = 1;
    stack<int> st;
    for(int i = 0;i<n;i++){
        if(k== 0)break;
        if(s[i] == '(')st.push(i);
        else used[st.top()] = true,st.pop(),used[i]= true,k-=2;

    }    
    for(int i = 0;i<n;i++){
        if(used[i])cout<<s[i];
    }
    cout<<endl;

    return 0;
}