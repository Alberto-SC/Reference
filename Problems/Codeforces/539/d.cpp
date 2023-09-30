#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    int n = s.size();
    for(int i = 0,j =n-1;i<=j;i++,j--){
        if(s[i]!=s[j])
            return false;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int nt = 0;
    for(int i = 0; i < n; i++) 
        nt += s[i] != s[0];
    string t = s;
    if(nt>1){
        for(int i = 0; i < n; ++i) {
            t = t.back() + t;
            t.pop_back();
            if (s != t && isPalindrome(t)) 
                return cout<<1<<endl,0;
        }
        return cout<<2<<endl,0;
    }
    else 
        return cout<<"Impossible"<<endl,0;
    return 0;
}