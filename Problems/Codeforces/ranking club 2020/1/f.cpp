#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int contA = 0,contB = 0,contC = 0,i = 0;
    while(s[i] == 'a'&& i<n){contA++;i++;}

    if(i== 0|| i == n)return cout<<"NO"<<endl,0;

    while(s[i] == 'b' && i<n){contB++;i++;}
    
    if(s[i] == 'A'|| i ==n || contB == 0)return cout<<"NO"<<endl,0;
    
    while(s[i] == 'c' && i<n){contC++;i++;}


    // cout<<contA<<" "<<contB<<" "<<contC<<endl;
    if(i<=n-1)return cout<<"NO"<<endl,0;
    if(contC == contA || contC == contB)return cout<<"YES"<<endl,0;
    cout<<"NO"<<endl;
    return 0;
}