#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+="Z";
    set<char>ss;
    int mx = 0;
    for(int i = 0;i<=n;i++){
        if(s[i]>='A' && s[i]<='Z')mx = max(mx,(int)ss.size()),ss.clear();
        else ss.insert(s[i]);

    }
    cout<<mx<<endl;
    return 0;
}