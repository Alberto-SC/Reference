#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    string s;
    int cont = 1;
    while(t--){
        cin>>n;
        cin>>s;
        bool flag = true;
        int A = 0,B = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== 'A')A++;
            else B++;
        }
        if(A == n/2 && B == (n+1)/2)
            cout<<"Case #"<<cont<<": Y"<<endl;
        else if(B == n/2 && A == (n+1)/2)
            cout<<"Case #"<<cont<<": Y"<<endl;
        else 
            cout<<"Case #"<<cont<<": N"<<endl;
        cont++;
    }

    return 0;
}