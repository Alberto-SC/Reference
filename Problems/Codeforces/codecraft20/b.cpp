#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,ansi,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        ansi = 0;
        string result= string(n,'z');
        char mn = 'z';
        for(int i = 0;i<n;i++)if(s[i]<mn)mn = s[i];
        for(int i = n-1;i>=0;i--){
            if(s[i] ==mn){
                string aux = "";
                string aux2 = s;
                if((n-i)%2==1)
                   reverse(aux2.begin(),aux2.begin()+i);
                aux = s.substr(i)+aux2.substr(0,i);
                if(aux<=result)result = aux,ansi = i+1;
            }
        } 
        cout<<result<<endl<<ansi<<endl;
    }
    return 0;
}