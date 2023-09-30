#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n = s.size();
        bool flag = true;
        for(int i = 1;i<n;i++){
            if(s[i] == 'a'){if(s[i-1]!= 'z')flag = false;}
            else if(s[i]!= s[i-1]+1){flag = false;break;}
        }
        
        flag?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}