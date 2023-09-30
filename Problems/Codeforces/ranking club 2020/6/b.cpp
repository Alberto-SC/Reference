#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    string s;
    cin>>s>>k;
    n = s.size();
    int count = 0,ans = 0;
    int i = 0;
    for(i=n-1;i>=0;i--) {
        if(s[i] == '0') count++;
            else ans++;
        if(count == k) break;
    }
    if(i == -1) ans = n - 1;
    cout<<ans<<endl;
    return 0;
}