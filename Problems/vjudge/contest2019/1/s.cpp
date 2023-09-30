#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int t;
    cin>>t;
    while(t--){
        cin>>a;
        string c;
        sort(a.begin(),a.end());
        if(a[0] == a[a.size()-1])cout<<-1<<endl;
        else cout<<a<<endl;
    }
    return 0;
}