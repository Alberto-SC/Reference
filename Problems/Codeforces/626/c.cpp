#include <bits/stdc++.h>
using namespace std;
bool areParanthesisBalanced(string expr){ 
    stack<char> s; 
    char x; 
     for (int i=0; i<expr.length(); i++){ 
        if (expr[i]=='(') { 
            s.push(expr[i]); 
            continue; 
        } 
        if (s.empty()) 
           return false;   
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
    }
    return true;
}   
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 0,lasti=0,ans = 0,open= 0,close = 0; 
    for(int i = 0;i<n;i++){
        if(s[i]== '(')open++;
        else close++;
    }
    if(open!=close)return cout<<-1<<endl,0;
    for(int i = 0;i<n;i++){
        if(s[i]== '(')count++;
        else count--;
        if(count == 0){
            bool flag = areParanthesisBalanced(s.substr(lasti,(i-lasti)+1));
            // cout<<s.substr(lasti,(i-lasti)+1)<<" "<<flag<<endl;            
            if(!flag)ans+=(i-lasti)+1;
            lasti = i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}