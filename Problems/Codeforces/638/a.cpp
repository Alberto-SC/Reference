#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;   
        string s(n+1,'0');
        s[0] ='1';
        for(int i = (n/2)+1;i<n;i++)s[i] ='1';
        // cout<<s<<endl;
        int num = stoi(s,nullptr,2);
        s = string(n+1,'1');
        s[0] ='0';
        s[n] ='0';
        for(int i = (n/2)+1;i<n;i++)s[i] ='0';
        int num2 = stoi(s,nullptr,2);
        // cout<<s<<endl;
        cout<<abs(num2-num);
    }
    return 0;
}