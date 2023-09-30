#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;    double p;
    cin>>s>>p;
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    int n = s.size();
    int B = 0,W = 0;
    int cont = 0;
    for(int i = 0;i<n;i++){
        cont++;
        if(s[i] == '?')W++;
        if(s[i] == '1')B++;
    }
    cout<<(B + W*p)/cont;
    
    return 0;
}