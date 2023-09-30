#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    int j = 0;
    for(int i = 0;i<n;i = j){
        if(s[i] == 'x'){
            j = i;
            while(s[j] == 'x')++j;
            if(j-i>2)ans+=(j-i)-2;
        }
        else j = i+1;
    }
    cout<<ans<<endl;
    return 0;
}