#include <bits/stdc++.h>
using namespace std;
int k = 26;
#define MOD(n) ( ( ((n) % (k)) + (k) ) % (k))
int main(){
    int n,s;
    cin>>n>>s;
    string t;
    cin.ignore();
    for(int i= 0;i<n;i++){
        getline(cin,t);
        string ans= t;
        // cout<<t;
        for(int j = 0;j<t.size();j++){
            if(t[j]>='A' && t[j]<='Z'){
                ans[j] = (char)((MOD((t[j]-'A')-s))+'A');
            }
            if(t[j]>='a' && t[j]<='z'){
                 ans[j] = (char)((MOD((t[j]-'a')-s))+'a');
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

0.000000 0.475606 0.401168 0.289732 0.062449
0.524394 0.000000 0.861276 0.509354 0.373818
0.598832 0.138724 0.000000 0.325639 0.421171
0.710268 0.490646 0.674361 0.000000 0.200146
0.937551 0.626182 0.578829 0.799854 0.000000