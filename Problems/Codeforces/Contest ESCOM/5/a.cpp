#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,contA = 0,contB = 0,j,k;
    string s,A = "LCS",B ="PCMS";
    cin>>s;
    n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='L')
            if(i+2<n && s[i+1]=='S'&&s[i+2]=='C')contA++;
        
        if(s[i]=='P')
            if(i+3<n && s[i+1]=='C'&&s[i+2]=='M'&&s[i+3]=='S')contB++;
    }
    if(contA>contB)cout<<"LSC";
    else if( contA == contB)cout<<"Tie";
    else cout<<"PCMS";
    return 0;
}