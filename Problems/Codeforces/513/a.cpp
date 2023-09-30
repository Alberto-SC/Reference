#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int cont = 0;
    for(int i =0;i<n;i++){
        if(s[i]=='8')cont++;
    }
    int mx = (n/11);
    if(cont>=mx)cout<<mx<<endl;
    else cout<<cont<<endl;
    return 0;
}