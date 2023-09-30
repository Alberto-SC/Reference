#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>n;
    string s;
    vector<int> b(1000001,true); 
    for(int i = 0;i<n;i++){
        cin>>s;
        int num;
        if(s.size()<=7 && s[0]!= '-')
            num = stoi(s);
        else continue;
        if(num<=1000000)
            b[num]= false;
    }   
    for(int i = 0;i<=1000000;i++)if(b[i]){cout<<i<<endl;break;}
    return 0;
}