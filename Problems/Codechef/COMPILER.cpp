#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;
        int n = s.size();
        int mx = -1;
        for(int i =0;i<n;i++){
            if(s[i]== '>' && st.empty())break;
            else if(s[i]== '>'){
                st.pop();
                if(st.empty())mx = i;
            }
            else 
                st.push(s[i]);
        }
        cout<<mx+1<<endl;
    }
    return 0;
}